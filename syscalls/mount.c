#include <sys/mount.h>
#include "libc/syscall.h"

syscall5(int, mount, const char *, const char *, const char *, unsigned long, const void *)
