#include <unistd.h>
#include "libc/syscall.h"

#ifdef __NR_exit_group
#define __NR___sys_exit_group	__NR_exit_group

#undef	__syscall_return
#define __syscall_return(type, res)	\
	while (1)			// make GCC warning happy

syscall1(void, __sys_exit_group, int)
#endif
