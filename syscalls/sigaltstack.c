#include <signal.h>
#include "libc/syscall.h"

syscall2(int, sigaltstack, const stack_t *, stack_t *)
