#include "libc/symbols.h"
#include <errno.h>

// FIXME: must be initialized ???
int errno = 0;				// for all syscalls and others
