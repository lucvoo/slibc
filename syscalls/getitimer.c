#include <sys/time.h>
#include "libc/syscall.h"

syscall2(int, getitimer, int, struct itimerval *)
