#include "libc/sched.h"
#include "libc/syscall.h"

#define __NR___sys_clone	__NR_clone

// arg1: int flags
// arg2: void* child_stack

syscall2(int, __sys_clone, int, void *)
