#include <unistd.h>
#include "arch/endian.h"
#include "libc/syscall.h"
#include "limits.h"

#if (WORD_BIT == 32)
#define __NR___sys_pread64	__NR_pread64

static inline syscall5(ssize_t, __sys_pread64, int, void *, size_t, unsigned, unsigned)

	 ssize_t pread64(int fd, void *buf, size_t count, loff_t offset)
{
	unsigned hi = offset & 0xffffffff;
	unsigned lo = offset >> 32;

	return __sys_pread64(fd, buf, count, __LONG_LONG_PAIR(hi, lo));
}

#else
#error "not yet implemented"
#endif
