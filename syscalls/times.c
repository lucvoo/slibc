#include <sys/times.h>
#include "libc/syscall.h"

syscall1(clock_t, times, struct tms *)
