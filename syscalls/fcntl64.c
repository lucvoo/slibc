#include <fcntl.h>
#include <stdarg.h>
#include "libc/syscall.h"

#ifdef __NR_fcntl64
#define __NR___sys_fcntl64	__NR_fcntl64

static inline syscall3(int, __sys_fcntl64, unsigned int, unsigned int, unsigned long)

	 int fcntl64(int fd, int cmd, ...)
{
	unsigned long arg;
	va_list ap;

	va_start(ap, cmd);
	arg = va_arg(ap, unsigned long);
	va_end(ap);

	return __sys_fcntl64(fd, cmd, arg);
}

// FIXME: can we fix this kludge ?

#endif
