#include <unistd.h>
#include "libc/syscall.h"

syscall2(int, sethostname, const char *, size_t)
