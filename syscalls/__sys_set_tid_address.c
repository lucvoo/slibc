#include "libc/sys_calls.h"
#include "libc/syscall.h"

#define __NR___sys_set_tid_address __NR_set_tid_address

syscall1(int, __sys_set_tid_address, int *)
