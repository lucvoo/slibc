#include <sys/vfs.h>			// FIXME
#include "libc/syscall.h"

syscall2(int, statfs, const char *, struct statfs *)
