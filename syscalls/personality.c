#include <unistd.h>
#include "libc/syscall.h"

// FIXME: where to put the prototypes ???
int personality(unsigned long);

syscall1(int, personality, unsigned long)
