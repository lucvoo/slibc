#include <attr/xattr.h>
#include "libc/syscall.h"

syscall5(int, setxattr, const char *, const char *, const void *, size_t, int)
