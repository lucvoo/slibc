#include <unistd.h>
#include "libc/syscall.h"
#include "libc/config.h"

syscall0(uid_t, geteuid)
