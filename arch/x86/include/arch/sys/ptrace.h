#ifndef _SYS_PTRACE_H
#define _SYS_PTRACE_H

#include <types/pid_t.h>

#define PTRACE_TRACEME		   0
#define PTRACE_PEEKTEXT		   1
#define PTRACE_PEEKDATA		   2
#define PTRACE_PEEKUSR		   3
//#define PTRACE_PEEKUSER                  PTRACE_PEEKUSR
#define PTRACE_POKETEXT		   4
#define PTRACE_POKEDATA		   5
#define PTRACE_POKEUSR		   6
#define PTRACE_CONT		   7
#define PTRACE_KILL		   8
#define PTRACE_SINGLESTEP	   9
#define PTRACE_ATTACH		0x10
#define PTRACE_DETACH		0x11
#define PTRACE_SYSCALL		  24

#define PTRACE_GETREGS            12
#define PTRACE_SETREGS            13
#define PTRACE_GETFPREGS          14
#define PTRACE_SETFPREGS          15
#define PTRACE_GETFPXREGS         18
#define PTRACE_SETFPXREGS         19
#define PTRACE_SETOPTIONS         21

// options set using PTRACE_SETOPTIONS
#define PTRACE_O_TRACESYSGOOD     0x00000001

#define EBX 0
#define ECX 1
#define EDX 2
#define ESI 3
#define EDI 4
#define EBP 5
#define EAX 6
#define DS 7
#define ES 8
#define FS 9
#define GS 10
#define ORIG_EAX 11
#define EIP 12
#define CS  13
#define EFL 14
#define UESP 15
#define SS   16
#define FRAME_SIZE 17

/* this struct defines the way the registers are stored on the
   stack during a system call. */

struct pt_regs {
	long		ebx;
	long		ecx;
	long		edx;
	long		esi;
	long		edi;
	long		ebp;
	long		eax;
	int		xds;
	int		xes;
	long		orig_eax;
	long		eip;
	int		xcs;
	long		eflags;
	long		esp;
	int		xss;
};

long ptrace(long request, pid_t pid, void *addr, void *data);

#endif
