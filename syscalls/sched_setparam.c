#include <sched.h>
#include "libc/syscall.h"

syscall2(int, sched_setparam, pid_t, const struct sched_param *)
