#include <sys/swap.h>
#include "libc/syscall.h"

syscall1(int, swapoff, const char *)
