#include <sys/stat.h>
#include "libc/syscall.h"

syscall2(int, chmod, const char *, mode_t)
