#include <unistd.h>
#include "libc/syscall.h"

syscall2(int, dup2, int, int)
