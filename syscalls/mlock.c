#include <sys/mman.h>
#include "libc/syscall.h"

syscall2(int, mlock, const void *, size_t)
