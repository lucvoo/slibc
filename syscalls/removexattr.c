#include <attr/xattr.h>
#include "libc/syscall.h"

syscall2(int, removexattr, const char *, const char *)
