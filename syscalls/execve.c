#include <unistd.h>
#include "libc/syscall.h"

typedef char *const cpca_t[];

syscall3(int, execve, const char *, cpca_t, cpca_t)
