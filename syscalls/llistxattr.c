#include <attr/xattr.h>
#include "libc/syscall.h"

syscall3(ssize_t, llistxattr, const char *, char *, size_t)
