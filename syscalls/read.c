#include <unistd.h>
#include "libc/syscall.h"

syscall3(ssize_t, read, int, void *, size_t)
