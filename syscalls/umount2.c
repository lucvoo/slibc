#include <sys/mount.h>
#include "libc/syscall.h"

syscall2(int, umount2, const char *, int)
