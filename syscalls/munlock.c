#include <sys/mman.h>
#include "libc/syscall.h"

syscall2(int, munlock, const void *, size_t)
