#include <unistd.h>
#include "libc/syscall.h"

syscall3(ssize_t, write, int, const void *, size_t)
