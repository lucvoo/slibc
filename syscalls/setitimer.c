#include <sys/time.h>
#include "libc/syscall.h"

syscall3(int, setitimer, int, const struct itimerval *, struct itimerval *)
