#include <sys/stat.h>
#include "libc/syscall.h"

syscall2(int, fchmod, int, mode_t)
