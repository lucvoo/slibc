#include <sched.h>
#include "libc/syscall.h"

syscall3(int, sched_setscheduler, pid_t, int, const struct sched_param *)
