#include <unistd.h>
#include "libc/syscall.h"
#include "libc/brk.h"

// arg: new end of data segment
//      if 0, return the actual memory top
// ret: always the actual memory top (after the call)

#define __NR___sys_brk	__NR_brk
#undef	__syscall_return
#define __syscall_return(type, res)	return (type) (res)

syscall1(void *, __sys_brk, void *)
