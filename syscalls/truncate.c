#include <unistd.h>
#include "libc/syscall.h"

syscall2(int, truncate, const char *, off_t)
