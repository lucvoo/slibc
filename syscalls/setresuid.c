#include <unistd.h>
#include "libc/syscall.h"
#include "libc/config.h"

syscall3(int, setresuid, uid_t, uid_t, uid_t)
