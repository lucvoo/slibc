#include <attr/xattr.h>
#include "libc/syscall.h"

syscall2(int, fremovexattr, int, const char *)
