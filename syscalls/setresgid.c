#include <unistd.h>
#include "libc/syscall.h"
#include "libc/config.h"

syscall3(int, setresgid, gid_t, gid_t, gid_t)
