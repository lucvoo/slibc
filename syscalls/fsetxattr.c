#include <attr/xattr.h>
#include "libc/syscall.h"

syscall5(int, fsetxattr, int, const char *, const void *, size_t, int)
