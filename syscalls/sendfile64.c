#include <sys/sendfile.h>
#include "libc/syscall.h"

#ifdef __NR_sendfile64

syscall4(ssize_t, sendfile64, int, int, loff_t *, size_t)
#endif
