#include <sys/io.h>
#include "libc/syscall.h"

#ifdef __NR_iopl
syscall1(int, iopl, int)
#endif
