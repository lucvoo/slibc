#include <fcntl.h>
#include <stdarg.h>
#include "libc/syscall.h"

#define __NR___sys_fcntl	__NR_fcntl

static inline syscall3(int, __sys_fcntl, int, int, unsigned long)

	 int fcntl(int fd, int cmd, ...)
{
	unsigned long arg;
	va_list ap;

	va_start(ap, cmd);
	arg = va_arg(ap, unsigned long);
	va_end(ap);

	return __sys_fcntl(fd, cmd, arg);
}

// FIXME: can we fix this kludge ?
