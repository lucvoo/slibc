#include <unistd.h>
#include "libc/syscall.h"
#include "arch/libc/config.h"

#ifdef CONFIG_UID16
syscall3(int, chown32, const char *, uid32_t, gid32_t)
#endif
