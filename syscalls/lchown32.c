#include <unistd.h>
#include "libc/syscall.h"
#include "libc/config.h"

#ifdef CONFIG_UID16
syscall3(int, lchown32, const char *, uid32_t, gid32_t)
#endif
