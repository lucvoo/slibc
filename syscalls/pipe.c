#include <unistd.h>
#include "libc/syscall.h"

typedef int i2a_t[2];

syscall1(int, pipe, i2a_t)
