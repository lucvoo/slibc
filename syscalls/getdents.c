#include <dirent.h>
#include "libc/syscall.h"

#define __NR___sys_getdents __NR_getdents

syscall3(int, __sys_getdents, unsigned int, struct dirent *, unsigned int)
