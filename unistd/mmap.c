#include <sys/mman.h>
#include <limits.h>
#include <errno.h>
#include "libc/cdefs.h"

void *mmap(void *start, size_t length, int prot, int flags, int fd, off_t offset)
{
	if (__unlikely(offset & (PAGESIZE - 1))) {
		errno = EINVAL;
		return MAP_FAILED;
	}

	return mmap2(start, length, prot, flags, fd, offset / PAGESIZE);
}
