#include <sys/mman.h>
#include "libc/syscall.h"

syscall3(int, msync, void *, size_t, int)
