#include <sched.h>
#include "libc/syscall.h"

syscall1(int, sched_getscheduler, pid_t)
