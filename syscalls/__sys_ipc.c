#include "arch/libc/config.h"

#ifdef ARCH_NEED_SYS_IPC
#include "libc/syscall.h"
#include "libc/ipccall.h"

#define __NR___sys_ipc	__NR_ipc

syscall6(int, __sys_ipc, unsigned int, int, int, int, void *, long)
#endif
