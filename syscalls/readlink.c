#include <unistd.h>
#include "libc/syscall.h"

syscall3(int, readlink, const char *restrict, char *restrict, size_t)
