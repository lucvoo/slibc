#ifndef _ARCH_TYPES_S_PT_REGS_H
#define _ARCH_TYPES_S_PT_REGS_H

struct pt_regs {
	unsigned long gpr[32];
	unsigned long nip;
	unsigned long msr;
	unsigned long orig_gpr3;
	unsigned long ctr;
	unsigned long link;
	unsigned long xer;
	unsigned long ccr;
	unsigned long mq;
	unsigned long trap;
	unsigned long dar;
	unsigned long dsisr;
	unsigned long result;
};

#endif
