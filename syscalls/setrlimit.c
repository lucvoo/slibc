#include <sys/resource.h>
#include "libc/syscall.h"

syscall2(int, setrlimit, int, const struct rlimit *)
