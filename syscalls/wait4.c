#include <sys/wait.h>
#include "libc/syscall.h"

syscall4(pid_t, wait4, pid_t, int *, int, struct rusage *)
