#include <unistd.h>
#include "libc/syscall.h"

// FIXME? : SUS want the new nice value for result and not 0/-1
syscall1(int, nice, int)
