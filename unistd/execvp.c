#include <unistd.h>
#include <errno.h>
#include <string.h>			// for strlen() & memcpy()
#include <stdlib.h>			// for getenv()
#include <paths.h>			// for _PATH_DEFPATH
#include "libc/unistd.h"		// for __libc_execsh()
#include "libc/cdefs.h"

int execvp(const char *file, char *const argv[])
{
	const char *cur;		// current value of $PATH
	size_t flen;			// length of the file name
	int access_err = 0;		// report EACCES error
	size_t n;

	for (n = 0; argv[n]; n++) ;

	// absolute/relative path
	if (strchr(file, '/')) {
		execve(file, argv, environ);
		if (errno == ENOEXEC)
			__libc_execsh(file, n, argv);
		return -1;
	}
	// must search through the PATH env var
	flen = strlen(file);
	cur = getenv("PATH");
	if (!cur)
		cur = _PATH_DEFPATH;

	for (; cur;) {
		char path[PATH_MAX];
		const char *nxt;	// next value of $PATH
		size_t len;		// size of the current path

		if (__unlikely(cur[0] == ':')) {
			cur++;		// FIXME: ignore multiple & leading ':'
			continue;
		}

		nxt = strchr(cur, ':');
		if (!nxt) {
			len = strlen(cur);
			nxt = NULL;
		} else {
			len = (nxt - cur);
			nxt++;
		}

		if (__unlikely((len + 1 + flen + 1) > PATH_MAX)) {
			errno = ENAMETOOLONG;
			return -1;
		}
		memcpy(path, cur, len);
		path[len] = '/';
		memcpy(path + len + 1, file, flen + 1);
		execve(path, argv, environ);
		if (errno == ENOEXEC)
			__libc_execsh(path, n, argv);

		switch (errno) {
		case EACCES:
			access_err = 1;
			// fall through
		case ENOENT:
		case ENOTDIR:
			break;		// try next path

		default:
			return -1;
		}

		cur = nxt;
	}

	if (access_err)
		errno = EACCES;

	return -1;
}
