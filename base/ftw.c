#include <ftw.h>
#include <dirent.h>			// for readdir() & C°
#include <string.h>			// for strlen()
#include <limits.h>			// for PATH_MAX
#include <errno.h>			// for itself :)
#include "libc/cdefs.h"

// FIXME: stop recursion if depth < 0

// FIXME: Glibc treat symlink differently!
// FIXME: should we use stat() ot lstat()
//        SuS is ambiguous: say non-explicitely to use stat()
//                          but FTW_SL need lstat()
#define Stat(A,B)	lstat(A, B)

static
int ftw_dir(char dir[PATH_MAX], __ftw_fn_t fun, const struct stat *sdir, int depth)
{
	DIR *dp;
	struct dirent *de;
	size_t len_dir = strlen(dir);
	int rc;

	dp = opendir(dir);
	if (!dp)			// do not recurse if FTW_DNR
	{
		rc = fun(dir, sdir, FTW_DNR);
		return rc;
	}

	rc = fun(dir, sdir, FTW_D);
	if (rc)
		goto end;

	dir[len_dir++] = '/';
	while ((de = readdir(dp))) {
		struct stat sbuf;
		const char *nam;
		size_t len;
		size_t max = PATH_MAX - len_dir - 1;
		int flag;

		nam = de->d_name;
		// skip '.' & '..' entries
		if (nam[0] == '.') {
			if ((nam[1] == '\0') || (nam[1] == '.' && nam[2] == '\0'))
				continue;
		}
		// ensure that we have enough place to store the "dir/nam"
		len = strlen(nam);
		if (__unlikely(len > max)) {
			errno = ENAMETOOLONG;
			rc = -1;
			goto end;
		}
		// append the entry name to the directory
		__builtin_memcpy(dir + len_dir, nam, len + 1);

		if (Stat(dir, &sbuf) != 0)
			flag = FTW_NS;
		else {
			mode_t mode;

			mode = sbuf.st_mode;
			if (S_ISLNK(mode))
				flag = FTW_SL;
			else if (S_ISDIR(mode)) {
				flag = FTW_D;
			} else
				flag = FTW_F;	// FIXME: what if !S_IFREG ??
		}

		if (__likely(flag != FTW_D)) {
			rc = fun(dir, &sbuf, flag);
		} else {
			rc = ftw_dir(dir, fun, &sbuf, depth - 1);
		}

		if (rc)
			goto end;
	}

end:
	closedir(dp);

	return rc;
}

int ftw(const char *path, __ftw_fn_t fun, int depth)
{
	char dirname[PATH_MAX];
	struct stat sbuf;
	int flag;
	size_t len_dir;
	int rc;

	if (Stat(path, &sbuf) != 0)
		flag = FTW_NS;
	else {
		mode_t mode;

		mode = sbuf.st_mode;
		if (S_ISLNK(mode))
			flag = FTW_SL;
		else if (S_ISDIR(mode))
			flag = FTW_D;
		else
			flag = FTW_F;	// FIXME: what if !S_IFREG ??
	}

	// non-recursive case
	if (flag != FTW_D)
		return fun(path, &sbuf, flag);

	// recursive case
	len_dir = strlen(path);
	if (len_dir >= PATH_MAX) {
		errno = ENAMETOOLONG;
		return -1;
	}

	__builtin_memcpy(dirname, path, len_dir + 1);

	rc = ftw_dir(dirname, fun, &sbuf, depth);
	return rc;
}
