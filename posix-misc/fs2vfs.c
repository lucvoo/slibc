#include <sys/statfs.h>
#include <sys/statvfs.h>
#include <limits.h>

// FIXME: 2.6's struct statfs have a "f_frsize" field
void __statfs2vfs(struct statvfs *vfs, const struct statfs *fs)
{
	vfs->f_bsize = fs->f_bsize;
	vfs->f_frsize = fs->f_bsize;	// what the difference ??
	vfs->f_blocks = fs->f_blocks;
	vfs->f_bfree = fs->f_bfree;
	vfs->f_bavail = fs->f_bavail;
	vfs->f_files = fs->f_files;
	vfs->f_ffree = fs->f_ffree;
	vfs->f_favail = fs->f_files - fs->f_ffree;	// FIXME ???

	// kernel's fsid is int val[2]
	// posix's  fsid is unsigned long
	vfs->f_fs_id = fs->f_fsid.val[0];
#if 2*WORD_BIT == LONG_BIT
	vfs->f_fs_id |= fs->f_fsid.val[1] << (8 * sizeof(fs->f_fsid.val[0]));
#endif

	vfs->f_flag = 0;		// FIXME!
	vfs->f_namemax = fs->f_namelen;

}
