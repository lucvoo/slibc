#include <attr/xattr.h>
#include "libc/syscall.h"

syscall3(ssize_t, flistxattr, int, char *, size_t)
