#include <attr/xattr.h>
#include "libc/syscall.h"

syscall2(int, lremovexattr, const char *, const char *)
