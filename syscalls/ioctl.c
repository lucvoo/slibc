#include <sys/ioctl.h>
#include <stdarg.h>
#include "libc/syscall.h"

#define __NR___sys_ioctl	__NR_ioctl
static inline syscall3(int, __sys_ioctl, int, int, unsigned long)

	 int ioctl(int fd, int request, ...)
{
	va_list ap;
	unsigned long arg;

	va_start(ap, request);
	arg = va_arg(ap, unsigned long);
	va_end(ap);

	return __sys_ioctl(fd, request, arg);
}

// FIXME: can we fix this kludge ?
