#include <sched.h>
#include "libc/syscall.h"

syscall2(int, sched_rr_get_interval, pid_t, struct timespec *)
