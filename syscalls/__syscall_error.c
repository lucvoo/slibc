#include "arch/libc/syscall.h"
#include <errno.h>

#ifdef __i386__
__attribute__ ((regparm(1)))
#endif
	 int __syscall_error(int rc)
{
	errno = -rc;

	return -1;
}
