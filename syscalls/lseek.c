#include <unistd.h>
#include "libc/syscall.h"

syscall3(off_t, lseek, int, off_t, int)
