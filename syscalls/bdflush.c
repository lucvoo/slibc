#include <sys/kdaemon.h>
#include "libc/syscall.h"

syscall2(int, bdflush, int, long int)
