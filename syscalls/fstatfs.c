#include <sys/vfs.h>			// FIXME
#include "libc/syscall.h"

syscall2(int, fstatfs, int, struct statfs *)
