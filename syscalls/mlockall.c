#include <sys/mman.h>
#include "libc/syscall.h"

syscall1(int, mlockall, int)
