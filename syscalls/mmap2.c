#include <sys/mman.h>
#include "libc/syscall.h"

syscall6(void *, mmap2, void *, size_t, int, int, int, off_t)
