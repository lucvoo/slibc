#ifndef _ARCH_TYPES_MCONTEXT_T_H
#define _ARCH_TYPES_MCONTEXT_T_H

typedef struct {
	unsigned long __trap_no;
	unsigned long __error_code;
	unsigned long __oldmask;
	unsigned long __arm_r0;
	unsigned long __arm_r1;
	unsigned long __arm_r2;
	unsigned long __arm_r3;
	unsigned long __arm_r4;
	unsigned long __arm_r5;
	unsigned long __arm_r6;
	unsigned long __arm_r7;
	unsigned long __arm_r8;
	unsigned long __arm_r9;
	unsigned long __arm_r10;
	unsigned long __arm_fp;
	unsigned long __arm_ip;
	unsigned long __arm_sp;
	unsigned long __arm_lr;
	unsigned long __arm_pc;
	unsigned long __arm_cpsr;
	unsigned long __fault_address;
} mcontext_t;

#endif
