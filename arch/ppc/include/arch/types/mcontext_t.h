#ifndef _ARCH_TYPES_MCONTEXT_T_H
#define _ARCH_TYPES_MCONTEXT_T_H

#include <types/s_pt_regs.h>

typedef struct {
	unsigned long _unused[4];
	int signal;
	unsigned long handler;
	unsigned long oldmask;
	struct pt_regs *regs;
} mcontext_t;

#endif
