#include "arch/libc/config.h"

#ifndef HAVE_ARCH__EXIT

#include <unistd.h>
#include "libc/syscall.h"

#define __NR__exit	__NR_exit

#undef	__syscall_return
#define __syscall_return(type, res) \
	while (1)			// FIXME: make GCC warning happy

syscall1(void, _exit, int)
#endif
