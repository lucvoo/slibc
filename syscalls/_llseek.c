#include <unistd.h>
#include "libc/syscall.h"

#ifdef __NR__llseek

syscall5(int, _llseek, unsigned int, unsigned long, unsigned long, loff_t *, unsigned int)
#endif
