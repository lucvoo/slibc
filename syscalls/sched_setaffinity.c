#include <sched.h>
#include "libc/syscall.h"

#ifdef __NR_sched_setaffinity
syscall3(int, sched_setaffinity, pid_t, unsigned int, const unsigned long *)
#endif
