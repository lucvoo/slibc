#include <sys/stat.h>
#include "libc/syscall.h"

syscall1(mode_t, umask, mode_t)
