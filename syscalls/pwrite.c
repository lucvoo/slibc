#include <unistd.h>
#include "arch/endian.h"
#include "libc/syscall.h"
#include "limits.h"

#if (WORD_BIT == 32)
#define __NR_sys_pwrite64	__NR_pwrite64

static inline syscall5(ssize_t, sys_pwrite64, int, const void *, size_t, unsigned, unsigned)

	 ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset)
{
	unsigned hi = offset;
	unsigned lo = offset >> 31;	// sign extend

	return sys_pwrite64(fd, buf, count, __LONG_LONG_PAIR(hi, lo));
}

#else
#error "not yet implemented"
#endif
