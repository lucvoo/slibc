#include <unistd.h>
#include "libc/syscall.h"

syscall2(int, setpgid, pid_t, pid_t)
