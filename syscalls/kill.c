#include <signal.h>
#include "libc/syscall.h"

syscall2(int, kill, pid_t, int)
