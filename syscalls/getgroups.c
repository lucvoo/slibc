#include <unistd.h>
#include "libc/syscall.h"
#include "libc/config.h"

syscall2(int, getgroups, int, gid_t *)
