#include <time.h>
#include "libc/syscall.h"

syscall2(int, nanosleep, const struct timespec *, struct timespec *)
