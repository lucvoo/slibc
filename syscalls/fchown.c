#include <unistd.h>
#include "libc/syscall.h"
#include "libc/config.h"

syscall3(int, fchown, int, uid_t, gid_t)
