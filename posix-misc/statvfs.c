#include <sys/statvfs.h>
#include <sys/vfs.h>

void __statfs2vfs(struct statvfs *, const struct statfs *);

int statvfs(const char *restrict path, struct statvfs *restrict vfsbuf)
{
	struct statfs fsbuf;

	// Get as much information as possible from the system. 
	if (statfs(path, &fsbuf) < 0)
		return -1;

	__statfs2vfs(vfsbuf, &fsbuf);

	// We signal success if the statfs call succeeded. 
	return 0;
}
