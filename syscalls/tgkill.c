#include "libc/sys_calls.h"
#include "libc/syscall.h"

#ifdef __NR_tgkill

#define __NR___sys_tgkill	__NR_tgkill

syscall3(int, __sys_tgkill, int, int, int)
#endif
