#include <sys/sendfile.h>
#include "libc/syscall.h"

syscall4(ssize_t, sendfile, int, int, off_t *, size_t)
