#include <sys/fsuid.h>
#include "libc/syscall.h"
#include "libc/config.h"

syscall1(int, setfsuid, uid_t)
