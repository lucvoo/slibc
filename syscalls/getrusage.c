#include <sys/resource.h>
#include "libc/syscall.h"

syscall2(int, getrusage, int, struct rusage *)
