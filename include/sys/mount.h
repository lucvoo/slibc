#ifndef _SYS_MOUNT_H
#define _SYS_MOUNT_H

// mount(2) flags
#define MS_RDONLY	 1		// Mount read-only
#define MS_NOSUID	 2		// Ignore suid and sgid bits
#define MS_NODEV	 4		// Disallow access to device special files
#define MS_NOEXEC	 8		// Disallow program execution
#define MS_SYNCHRONOUS	16		// Writes are synced at once
#define MS_REMOUNT	32		// Alter flags of a mounted FS
#define MS_MANDLOCK	64		// Allow mandatory locks on an FS
#define MS_NOATIME	1024		// Do not update atime
#define MS_NODIRATIME	2048		// Do not update directory atime
#define MS_BIND		4096
#define MS_MOVE		8192
#define MS_REC		16384
#define MS_VERBOSE	32768
#define MS_ACTIVE	(1<<30)
#define MS_NOUSER	(1<<31)

/*
 * Superblock flags that can be altered by MS_REMOUNT
 */
#define MS_RMT_MASK	(MS_RDONLY|MS_SYNCHRONOUS|MS_MANDLOCK|MS_NOATIME|MS_NODIRATIME)

/*
 * Old magic mount flag and mask
 */
#define MS_MGC_VAL 0xC0ED0000
#define MS_MGC_MSK 0xffff0000

// umount2(2) flags
#define MNT_FORCE	0x1		// Attempt to forcibily umount
#define MNT_DETACH	0x2		// Just detach from the tree

int mount(const char *specialfile, const char *dir,
	  const char *filesystemtype, unsigned long mountflags, const void *data);
int umount(const char *dir);
int umount2(const char *dir, int flags);

#endif
