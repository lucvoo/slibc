#ifndef _FTW_H
#define _FTW_H

#include <sys/stat.h>

#define FTW_F		1		// Regular file
#define FTW_D		4		// Directory
#define FTW_DNR		5		// Directory without read permission
#define FTW_DP		6		// Directory with subdirectories visited
#define FTW_NS		0		// Unknown type; stat() fail
#define FTW_SL		8		// Symbolic link
#define FTW_SLN		9		// Symbolic link to non-existing file

#define FTW_PHYS	1		// do not follow symlink
#define FTW_MOUNT	2		// do not cross a mount point
#define FTW_DEPTH	4		// visit subdirs before itself
#define FTW_CHDIR	8		// change each dir before reading it

struct FTW {
	int		base;
	int		level;
};

typedef int (*__ftw_fn_t) (const char *, const struct stat *, int);
typedef int (*__nftw_fn_t) (const char *, const struct stat *, int, struct FTW *);

int ftw(const char *path, __ftw_fn_t fn, int depth);
int nftw(const char *path, __nftw_fn_t fn, int depth, int flags);

#endif
