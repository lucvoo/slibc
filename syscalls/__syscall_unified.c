#include "arch/libc/syscall.h"
#include <errno.h>

#ifdef __i386
__attribute__ ((regparm(1)))
#endif
	 int __syscall_unified(long rc)
{
	if (__unlikely((unsigned long)rc >= (unsigned long)-4095)) {
		errno = -rc;
		rc = -1;
	}

	return rc;
}
