#include <unistd.h>
#include "libc/syscall.h"
#include "libc/config.h"

syscall1(int, setgid, gid_t)
