#include <sys/resource.h>
#include "libc/syscall.h"

syscall2(int, getrlimit, int, struct rlimit *)
