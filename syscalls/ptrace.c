#include <sys/ptrace.h>
#include "libc/syscall.h"

syscall4(long, ptrace, long, pid_t, void *, void *)
