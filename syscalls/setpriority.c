#include <sys/resource.h>
#include "libc/syscall.h"

syscall3(int, setpriority, int, int, int)
