#include <attr/xattr.h>
#include "libc/syscall.h"

syscall4(ssize_t, lgetxattr, const char *, const char *, void *, size_t)
