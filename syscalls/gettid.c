#include <unistd.h>
#include "libc/syscall.h"

#define __NR___sys_gettid	__NR_gettid

syscall0(pid_t, __sys_gettid)
