#ifndef _ARCH_TYPES_MCONTEXT_T_H
#define _ARCH_TYPES_MCONTEXT_T_H

struct _fpreg {
	unsigned short		__significand[4];
	unsigned short		__exponent;
};

struct _fpxreg {
	unsigned short		__significand[4];
	unsigned short		__exponent;
	unsigned short		__padding[3];
};

struct _xmmreg {
	unsigned long		__element[4];
};

struct _fpstate {
	unsigned long		__cw;
	unsigned long		__sw;
	unsigned long		__tag;
	unsigned long		__ipoff;
	unsigned long		__cssel;
	unsigned long		__dataoff;
	unsigned long		__datasel;
	struct _fpreg		_st[8];
	unsigned short		__status;
	unsigned short		__magic;	// 0xffff = regular FPU data only

	unsigned long		_fxsr_env[6];	// FXSR FPU env is ignored
	unsigned long		__mxcsr;
	unsigned long		__reserved;
	struct _fpxreg		_fxsr_st[8];	// FXSR FPU reg data is ignored
	struct _xmmreg		_xmm[8];
	unsigned long		__padding[56];
};

typedef struct {
	unsigned short __gs,	__gsh;
	unsigned short __fs,	__fsh;
	unsigned short __es,	__esh;
	unsigned short __ds,	__dsh;
	unsigned long		__edi;
	unsigned long		__esi;
	unsigned long		__ebp;
	unsigned long		__esp;
	unsigned long		__ebx;
	unsigned long		__edx;
	unsigned long		__ecx;
	unsigned long		__eax;
	unsigned long		__trapno;
	unsigned long		__err;
	unsigned long		__eip;
	unsigned short __cs,	__csh;
	unsigned long		__eflags;
	unsigned long		__esp_at_signal;
	unsigned short __ss,	__ssh;
	struct _fpstate		*__fpstate;
	unsigned long		__oldmask;
	unsigned long		__cr2;
} mcontext_t;

#endif
