#include <sched.h>
#include "libc/syscall.h"

syscall2(int, sched_getparam, pid_t, struct sched_param *)
