#include <sys/mman.h>
#include "libc/syscall.h"

syscall3(int, mprotect, void *, size_t, int)
