#include <unistd.h>
#include "libc/syscall.h"

syscall2(int, ftruncate, int, off_t)
