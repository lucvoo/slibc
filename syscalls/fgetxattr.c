#include <attr/xattr.h>
#include "libc/syscall.h"

syscall4(ssize_t, fgetxattr, int, const char *, void *, size_t)
