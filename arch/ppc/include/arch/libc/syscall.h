#ifndef _ARCHLIBC_SYSCALL_H
#define _ARCH_LIBC_SYSCALL_H

#include <sys/syscall.h>
#include "libc/symbols.h"
#include "libc/cdefs.h"

int __syscall_error(int rc);
int __syscall_unified(long rc);

#undef	__syscall_return
#define __syscall_return__(type, res)	\
    return (type) res

#define __syscall_return(type, res)	__syscall_return__(type, res)

#define gen_syscall(type,name, nr)		\
{   unsigned long ret, err;			\
    register unsigned long r0 __asm__("r0") = __NR_##name;	\
    register unsigned long r3 __asm__("r3");	\
    register unsigned long r4 __asm__("r4");	\
    register unsigned long r5 __asm__("r5");	\
    register unsigned long r6 __asm__("r6");	\
    register unsigned long r7 __asm__("r7");	\
    register unsigned long r8 __asm__("r8");	\
						\
    LOAD_ARGS_##nr				\
						\
    __asm__ __volatile__ (			\
	"sc	\n\t"				\
	"mfcr %0\n\t"				\
	: "=&r" (r0), "=&r" (r3),  "=&r" (r4), "=&r" (r5),  "=&r" (r6), "=&r" (r7), "=&r" (r8)	\
	: "0" (__NR_##name)  ASM_ARGS_##nr	\
	: "cr0", "ctr", "memory", "r9", "r10","r11", "r12");			\
						\
    ret = r3;					\
    err = r0;					\
    if (__unlikely(err & 0x10000000))		\
	ret = __syscall_error(ret);		\
    __syscall_return(type, ret);		\
}

#define LOAD_ARG(N, R)		\
	r##R = (unsigned long) A##N;
#define ASM_ARG(N, R)		\
	#N  (r##R)

#define LOAD_ARGS_0
#define LOAD_ARGS_1	LOAD_ARGS_0 LOAD_ARG(1, 3)
#define LOAD_ARGS_2	LOAD_ARGS_1 LOAD_ARG(2, 4)
#define LOAD_ARGS_3	LOAD_ARGS_2 LOAD_ARG(3, 5)
#define LOAD_ARGS_4	LOAD_ARGS_3 LOAD_ARG(4, 6)
#define LOAD_ARGS_5	LOAD_ARGS_4 LOAD_ARG(5, 7)
#define LOAD_ARGS_6	LOAD_ARGS_5 LOAD_ARG(6, 8)

#define ASM_ARGS_0
#define ASM_ARGS_1	ASM_ARGS_0, ASM_ARG(1, 3)
#define ASM_ARGS_2	ASM_ARGS_1, ASM_ARG(2, 4)
#define ASM_ARGS_3	ASM_ARGS_2, ASM_ARG(3, 5)
#define ASM_ARGS_4	ASM_ARGS_3, ASM_ARG(4, 6)
#define ASM_ARGS_5	ASM_ARGS_4, ASM_ARG(5, 7)
#define ASM_ARGS_6	ASM_ARGS_5, ASM_ARG(6, 8)

#define syscall0(type,name)	\
	type name(void) \
	gen_syscall(type, name, 0)

#define syscall1(type,name,typ1) \
	type name(typ1 A1) \
	gen_syscall(type, name, 1)

#define syscall2(type,name,typ1,typ2) \
	type name(typ1 A1, typ2 A2) \
	gen_syscall(type, name, 2)

#define syscall3(type,name,typ1,typ2,typ3) \
	type name(typ1 A1, typ2 A2, typ3 A3) \
	gen_syscall(type, name, 3)

#define syscall4(type,name,typ1,typ2,typ3,typ4) \
	type name(typ1 A1, typ2 A2, typ3 A3, typ4 A4) \
	gen_syscall(type, name, 4)

#define syscall5(type,name,typ1,typ2,typ3,typ4,typ5) \
	type name(typ1 A1, typ2 A2, typ3 A3, typ4 A4, typ5 A5) \
	gen_syscall(type, name, 5)

#define syscall6(type,name,typ1,typ2,typ3,typ4,typ5,typ6) \
	type name(typ1 A1, typ2 A2, typ3 A3, typ4 A4, typ5 A5, typ6 A6) \
	gen_syscall(type, name, 6)

#endif
