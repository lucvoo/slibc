#include <unistd.h>
#include "libc/syscall.h"
#include "arch/libc/config.h"

#ifdef __NR_socketcall
#include "libc/socketcall.h"

#define __NR___sys_socketcall	__NR_socketcall

syscall2(int, __sys_socketcall, int, long *)
#endif
