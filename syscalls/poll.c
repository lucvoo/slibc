#include <sys/poll.h>
#include "libc/syscall.h"

syscall3(int, poll, struct pollfd *, unsigned int, int)
