#include <sys/mman.h>
#include "libc/syscall.h"

syscall3(int, madvise, void *, size_t, int)
 strong_alias(madvise, posix_madvise);
