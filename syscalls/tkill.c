#include <signal.h>
#include "libc/syscall.h"

#define __NR___sys_tkill	__NR_tkill

syscall2(int, __sys_tkill, pid_t, int)
