#include <sys/mman.h>
#include "libc/syscall.h"

syscall2(int, munmap, void *, size_t)
