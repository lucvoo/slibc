#include <sys/stat.h>
#include "libc/syscall.h"

syscall3(int, mknod, const char *, mode_t, dev_t)
