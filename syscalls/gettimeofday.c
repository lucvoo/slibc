#include <sys/time.h>
#include "libc/syscall.h"

syscall2(int, gettimeofday, struct timeval *, void *)
