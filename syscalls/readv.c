#include <sys/uio.h>
#include "libc/syscall.h"

syscall3(ssize_t, readv, int, const struct iovec *, int)
