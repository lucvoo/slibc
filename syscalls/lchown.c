#include <unistd.h>
#include "libc/syscall.h"
#include "libc/config.h"

syscall3(int, lchown, const char *, uid_t, gid_t)
