#include <sys/swap.h>
#include "libc/syscall.h"

syscall2(int, swapon, const char *, int)
