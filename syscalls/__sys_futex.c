#include "sys/time.h"
#include "libc/futex.h"
#include "libc/syscall.h"

#define __NR___sys_futex __NR_futex

syscall5(int, __sys_futex, void *, int, int, const struct timespec *, void *)
