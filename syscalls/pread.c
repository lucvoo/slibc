#include <unistd.h>
#include "arch/endian.h"
#include "libc/syscall.h"
#include "limits.h"

#if (WORD_BIT == 32)
#define __NR___sys_pread64	__NR_pread64

static inline syscall5(ssize_t, __sys_pread64, int, void *, size_t, unsigned, unsigned)

	 ssize_t pread(int fd, void *buf, size_t count, off_t offset)
{
	unsigned hi = offset;
	unsigned lo = offset >> 31;	// sign extend

	return __sys_pread64(fd, buf, count, __LONG_LONG_PAIR(hi, lo));
}

#else
#error "not yet implemented"
#endif
