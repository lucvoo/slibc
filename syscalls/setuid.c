#include <unistd.h>
#include "libc/syscall.h"
#include "libc/config.h"

syscall1(int, setuid, uid_t)
