#include <unistd.h>
#include "libc/syscall.h"

syscall2(int, symlink, const char *, const char *)
