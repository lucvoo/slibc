#ifndef LIBC_SYSCALL_H_
#define LIBC_SYSCALL_H_

#include <sys/syscall.h>
#include "libc/symbols.h"
#include "libc/cdefs.h"

__attribute__ ((regparm(1)))
	 int __syscall_error(int);
__attribute__ ((regparm(1)))
	 int __syscall_unified(long);

#undef	__syscall_return
#define __syscall_return(type, res)	\
	return (type) __syscall_unified((int) res)

#define syscall0(type,name)							\
type name(void)									\
{					\
	long __res;			\
	__asm__ __volatile__(		\
		"int $0x80"		\
		: "=a" (__res)		\
		: "0" (__NR_##name));	\
	__syscall_return(type,__res);	\
}

#define syscall1(type,name,type1)						\
type name(type1 arg1)								\
{					\
	long __res;			\
	__asm__ __volatile__(		\
		"int $0x80"		\
		: "=a" (__res)		\
		: "0" (__NR_##name), "b" ((long)(arg1)));			\
	__syscall_return(type,__res);	\
}

#define syscall2(type,name,type1,type2)						\
type name(type1 arg1,type2 arg2)						\
{					\
	long __res;			\
	__asm__ __volatile__(		\
		"int $0x80"		\
		: "=a" (__res)		\
		: "0" (__NR_##name), "b" ((long)(arg1)), "c" ((long)(arg2)));	\
	__syscall_return(type,__res);	\
}

#define syscall3(type,name,type1,type2,type3)					\
type name(type1 arg1,type2 arg2,type3 arg3)					\
{					\
	long __res;			\
	__asm__ __volatile__(		\
		"int $0x80"		\
		: "=a" (__res)		\
		: "0" (__NR_##name), "b" ((long)(arg1)), "c" ((long)(arg2)),	\
			  "d" ((long)(arg3)));					\
	__syscall_return(type,__res);	\
}

#define syscall4(type,name,type1,type2,type3,type4)				\
type name (type1 arg1, type2 arg2, type3 arg3, type4 arg4)			\
{					\
	long __res;			\
	__asm__ __volatile__(		\
		"int $0x80"		\
		: "=a" (__res)		\
		: "0" (__NR_##name), "b" ((long)(arg1)), "c" ((long)(arg2)),	\
		  "d" ((long)(arg3)), "S" ((long)(arg4)));			\
	__syscall_return(type,__res);	\
}

#define syscall5(type,name,type1,type2,type3,type4,type5)			\
type name (type1 arg1,type2 arg2,type3 arg3,type4 arg4,type5 arg5)		\
{					\
	long __res;			\
	__asm__ __volatile__(		\
		"int $0x80"		\
		: "=a" (__res)		\
		: "0" (__NR_##name), "b" ((long)(arg1)), "c" ((long)(arg2)),	\
		  "d" ((long)(arg3)), "S" ((long)(arg4)), "D" ((long)(arg5)));	\
	__syscall_return(type,__res);	\
}

#define syscall6(type,name,type1,type2,type3,type4,type5,type6)			\
type name (type1 arg1,type2 arg2,type3 arg3,type4 arg4,type5 arg5,type6 arg6)	\
{					\
	long __res;			\
	__asm__ __volatile__(		\
		"push %%ebp"		\
		"movl %%eax,%%ebp"	\
		"movl %1,%%eax"		\
		"int $0x80"		\
		"pop %%ebp"		\
		: "=a" (__res)		\
		: "i" (__NR_##name), "b" ((long)(arg1)), "c" ((long)(arg2)),	\
		  "d" ((long)(arg3)), "S" ((long)(arg4)), "D" ((long)(arg5)),	\
		  "0" ((long)(arg6)));	\
	__syscall_return(type,__res);	\
}

#endif
