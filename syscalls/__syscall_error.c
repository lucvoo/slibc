#include "arch/libc/syscall.h"
#include <errno.h>

#ifdef __i386__
__attribute__ ((regparm(1)))
#endif
	 int __syscall_error(int rc)
{
#if defined(__powerpc__)
	errno = rc;
#else
	errno = -rc;
#endif

	return -1;
}
