#include <sched.h>
#include "libc/syscall.h"

#ifdef __NR_sched_getaffinity
syscall3(int, sched_getaffinity, pid_t, unsigned int, unsigned long *)
#endif
