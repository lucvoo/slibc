#include <sys/prctl.h>
#include "libc/syscall.h"

syscall5(int, prctl, int, unsigned long, unsigned long, unsigned long, unsigned long)
