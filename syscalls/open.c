#include <fcntl.h>
#include <stdarg.h>

#include "libc/syscall.h"
#include "libc/sys_calls.h"

#define __NR___sys_open	__NR_open

static inline syscall3(int, __sys_open, const char *, int, int)

	 int open(const char *pathname, int oflags, ...)
{
	int mode;

	if (oflags & O_CREAT) {
		va_list ap;

		va_start(ap, oflags);
		mode = va_arg(ap, int);	// FIXME: mode is mode_t/u16
		va_end(ap);
	} else
		mode = 0;

	return __sys_open(pathname, oflags, mode);
}
