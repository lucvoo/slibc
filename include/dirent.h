#ifndef _DIRENT_H
#define _DIRENT_H

#include <sys/cdefs.h>

#include <values/__NAME_MAX.h>

#include <types/ino_t.h>
#include <types/off_t.h>

typedef struct __DIR DIR;

struct dirent {
	ino_t		d_ino;
	off_t		d_off;
	unsigned short	d_reclen;
//      unsigned short 	d_type;
	char		d_name[__NAME_MAX + 1];
};

int closedir(DIR *);
DIR *opendir(const char *);
struct dirent *readdir(DIR *);
int readdir_r(DIR * restrict, struct dirent *restrict, struct dirent **restrict);
void rewinddir(DIR *);
void seekdir(DIR *, long);
long telldir(DIR *);

#ifndef __STRICT_POSIX
int __sys_getdents(unsigned int fd, struct dirent *dirp, unsigned int count);

int scandir(const char *dir, struct dirent ***nlist,
	    int (*select) (const struct dirent *),
	    int (*compar) (const struct dirent **, const struct dirent **));

int alphasort(const struct dirent **a, const struct dirent **b);
int dirfd(DIR *);
#endif

#endif
