#include <sys/io.h>
#include "libc/syscall.h"

#ifdef __NR_ioperm

syscall3(int, ioperm, unsigned long int, unsigned long int, int)
#endif
