#ifndef _SYS_STAT_H
#define _SYS_STAT_H

	// extracted from <linux/stat.h>
#define S_IFMT		0170000
#define S_IFSOCK	0140000
#define S_IFLNK		0120000
#define S_IFREG		0100000
#define S_IFBLK		0060000
#define S_IFDIR		0040000
#define S_IFCHR		0020000
#define S_IFIFO		0010000

#define S_ISUID		0004000
#define S_ISGID		0002000
#define S_ISVTX		0001000

#define S_IRWXU		0000700
#define S_IRUSR		0000400
#define S_IWUSR		0000200
#define S_IXUSR		0000100

#define S_IRWXG		0000070
#define S_IRGRP		0000040
#define S_IWGRP		0000020
#define S_IXGRP		0000010

#define S_IRWXO		0000007
#define S_IROTH		0000004
#define S_IWOTH		0000002
#define S_IXOTH		0000001

#define S_ISSOCK(m)	(((m) & S_IFMT) == S_IFSOCK)
#define S_ISLNK(m)	(((m) & S_IFMT) == S_IFLNK)
#define S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)
#define S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#define S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#define S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#define S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)

#include "types/mode_t.h"
#include "types/dev_t.h"
#include "types/blksize_t.h"
#include "types/blkcnt_t.h"
#include "types/nlink_t.h"
#include "types/time_t.h"
#include "types/ino_t.h"
#include "types/uid_t.h"
#include "types/gid_t.h"
#include "types/off_t.h"

#include "types/s_stat.h"

#include <sys/cdefs.h>

int chmod(const char *file, mode_t mode);
int fchmod(int fd, mode_t mode);
int fstat(int filedes, struct stat *buf);
int lstat(const char *restrict filename, struct stat *restrict buf);
int mkdir(const char *path, mode_t mode);
int mkfifo(const char *path, mode_t mode);
int mknod(const char *path, mode_t mode, dev_t dev);
int stat(const char *restrict filename, struct stat *restrict buf);
mode_t umask(mode_t mask);

#endif
