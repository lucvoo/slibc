#include <sys/mman.h>
#include "libc/syscall.h"

syscall3(int, mincore, void *, size_t, unsigned char *)
