#include <unistd.h>
#include "libc/syscall.h"
#include "libc/config.h"

syscall2(int, setreuid, uid_t, uid_t)
