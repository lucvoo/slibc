#ifndef LIBC_SYSCALL_H_
#define LIBC_SYSCALL_H_

// Largely inspired by glibc

#include <sys/syscall.h>
#include "libc/symbols.h"
#include "libc/cdefs.h"

int __syscall_error(int rc);
int __syscall_unified(long rc);

#undef	__syscall_return
#define __syscall_return__(type, res)		\
    return (type) __syscall_unified((int) res)

#define __syscall_return(type, res)	__syscall_return__(type, res)

#define gen_syscall(type,name, nr)		\
{   LOAD_ARGS_##nr				\
    __asm__ __volatile__ (				\
	"swi	%1	@ syscall " #name	\
	: "=r" (res)				\
	: "i" (__NR_##name)  ASM_ARGS_##nr	\
	: "memory" );				\
__syscall_return(type, res);			\
}

#define EVAL(X)	X

#if 1
#define LOAD_ARG(N)	\
	register long r##N __asm__("r" #N) = (long) A##N;
#define ASM_ARG(N)	\
	, "r" (r##N)
#else
#define LOAD_ARG(N)	\
	register long r##N = (long) A##N;
#define ASM_ARG(N)	\
	, "r" #N (r##N)
#endif

#define LOAD_ARGS_0	\
	register long res __asm__("r0");
#define ASM_ARGS_0

#define LOAD_ARGS_1		\
	LOAD_ARGS_0 LOAD_ARG(0)
#define ASM_ARGS_1		\
	ASM_ARG(0)

#define LOAD_ARGS_2		\
	LOAD_ARGS_1 LOAD_ARG(1)
#define ASM_ARGS_2		\
	ASM_ARGS_1 ASM_ARG(1)

#define LOAD_ARGS_3		\
	LOAD_ARGS_2 LOAD_ARG(2)
#define ASM_ARGS_3		\
	ASM_ARGS_2 ASM_ARG(2)

#define LOAD_ARGS_4		\
	LOAD_ARGS_3 LOAD_ARG(3)
#define ASM_ARGS_4		\
	ASM_ARGS_3 ASM_ARG(3)

#define LOAD_ARGS_5		\
	LOAD_ARGS_4 LOAD_ARG(4)
#define ASM_ARGS_5		\
	ASM_ARGS_4 ASM_ARG(4)

#define LOAD_ARGS_6		\
	LOAD_ARGS_5 LOAD_ARG(5)
#define ASM_ARGS_6		\
	ASM_ARGS_5 ASM_ARG(5)

#define syscall0(type,name)	\
	type name(void) \
	gen_syscall(type, name, 0)

#define syscall1(type,name,typ1) \
	type name(typ1 A0) \
	gen_syscall(type, name, 1)

#define syscall2(type,name,typ1,typ2) \
	type name(typ1 A0,typ2 A1) \
	gen_syscall(type, name, 2)

#define syscall3(type,name,typ1,typ2,typ3) \
	type name(typ1 A0,typ2 A1,typ3 A2) \
	gen_syscall(type, name, 3)

#define syscall4(type,name,typ1,typ2,typ3,typ4) \
	type name(typ1 A0, typ2 A1, typ3 A2, typ4 A3) \
	gen_syscall(type, name, 4)

#define syscall5(type,name,typ1,typ2,typ3,typ4,typ5) \
	type name(typ1 A0,typ2 A1,typ3 A2,typ4 A3,typ5 A4) \
	gen_syscall(type, name, 5)

#define syscall6(type,name,typ1,typ2,typ3,typ4,typ5,typ6) \
	type name(typ1 A0,typ2 A1,typ3 A2,typ4 A3,typ5 A4,typ6 A5) \
	gen_syscall(type, name, 6)

#endif
