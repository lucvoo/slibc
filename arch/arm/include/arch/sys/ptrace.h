#ifndef _SYS_PTRACE_H
#define _SYS_PTRACE_H

#include <types/pid_t.h>

#define PTRACE_GETREGS          12
#define PTRACE_SETREGS          13
#define PTRACE_GETFPREGS        14
#define PTRACE_SETFPREGS        15

#define PTRACE_SETOPTIONS       21

// options set using PTRACE_SETOPTIONS
#define PTRACE_O_TRACESYSGOOD   0x00000001

struct pt_regs {
	long		uregs[18];
};

#define ARM_cpsr        uregs[16]
#define ARM_pc          uregs[15]
#define ARM_lr          uregs[14]
#define ARM_sp          uregs[13]
#define ARM_ip          uregs[12]
#define ARM_fp          uregs[11]
#define ARM_r10         uregs[10]
#define ARM_r9          uregs[9]
#define ARM_r8          uregs[8]
#define ARM_r7          uregs[7]
#define ARM_r6          uregs[6]
#define ARM_r5          uregs[5]
#define ARM_r4          uregs[4]
#define ARM_r3          uregs[3]
#define ARM_r2          uregs[2]
#define ARM_r1          uregs[1]
#define ARM_r0          uregs[0]
#define ARM_ORIG_r0     uregs[17]

long ptrace(long request, pid_t pid, void *addr, void *data);

#endif
