#include <sys/mman.h>
#include "libc/syscall.h"

syscall4(void *, mremap, void *, size_t, size_t, unsigned long)
