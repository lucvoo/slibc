#include "libc/config.h"
#include <stdlib.h>
#include <fcntl.h>			// for open()
#include <string.h>			// for memmove()
#include <unistd.h>			// for close() & chdir()
#include <errno.h>

char *realpath(const char *restrict path, char *restrict result)
{
	const char *file = NULL;
	char link[PATH_MAX];
	const char *curr = path;
	int saved_errno = errno;
	int fd;
	int rc;

#if defined(CONFIG_STRICT_SUS_COMPLIANCY)
	if (!path) {
		errno = EINVAL;
		return NULL;
	}
#endif

	fd = open(".", O_RDONLY);
	if (fd < 0)
		return NULL;

	rc = chdir(path);
	if (rc == 0)
		goto dir;

	if (errno != ENOTDIR)
		goto error;
	else
		errno = saved_errno;

	// the current path is not a dir
	// split into directory - filename
	curr = path;
	while (1) {
		const char *tmp;

		tmp = strrchr(curr, '/');
		if (tmp) {
			size_t len;

			file = tmp;
			len = file - curr;

			if (len >= PATH_MAX)
				goto toolong;

			memcpy(result, curr, len);
			result[len] = 0;
			rc = chdir(result);
			if (rc) {
				goto error;
			}
			curr = file + 1;
		}
		// curr can be a symlink
		rc = readlink(curr, link, PATH_MAX);
		if (rc == -1) {
			if (errno != EINVAL)
				goto error;

			errno = saved_errno;
			break;
		}
		// file was indeed a symlink
		if (rc >= PATH_MAX)
			goto toolong;

		link[rc] = 0;
		curr = link;
	}

dir:
	// the cwd is set to the "dirname" of path and
	if (!getcwd(result, PATH_MAX))
		goto error;

	// "file" may contain a filename to append to the dir
	if (file) {
		size_t len1 = strlen(result);
		size_t len2 = strlen(file);

		if ((len1 + len2 + 1) > PATH_MAX)
			goto toolong;

		memcpy(result + len1, file, len2 + 1);
	}

end:
	fchdir(fd);
	close(fd);
	return result;

toolong:
	errno = ENAMETOOLONG;
error:
	result = NULL;
	goto end;
}
