#include <sys/uio.h>
#include "libc/syscall.h"

syscall3(ssize_t, writev, int, const struct iovec *, int)
