#ifndef _SYS_MNTENT_H
#define _SYS_MNTENT_H

#include <stdio.h>

#define MOUNTED		"/etc/mtab"	// Deprecated

struct mntent {
	char	*mnt_fsname;		// Device or server for filesystem
	char	*mnt_dir;		// Directory mounted on
	char	*mnt_type;		// Type of filesystem: ufs, nfs, etc
	char	*mnt_opts;		// Comma-separated options for fs
	int	mnt_freq;		// Dump frequency (in days)
	int	mnt_passno;		// Pass number for `fsck'
};

int endmntent(FILE *);
struct mntent *getmntent_r(FILE * S, struct mntent *mp, char *buf, size_t size);
struct mntent *getmntent(FILE * S);
FILE *setmntent(const char *pathname, const char *type);

#endif
