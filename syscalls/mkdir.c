#include <sys/stat.h>
#include "libc/syscall.h"

syscall2(int, mkdir, const char *, mode_t)
