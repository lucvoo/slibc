#ifndef _TYPES_UCONTEXT_T_H
#define _TYPES_UCONTEXT_T_H

#include "types/mcontext_t.h"
#include "types/sigset_t.h"
#include "types/stack_t.h"

typedef struct __ucontext {
	unsigned long int uc_flags;
	struct __ucontext *uc_link;
	stack_t uc_stack;
	mcontext_t uc_mcontext;
	sigset_t uc_sigmask;
} ucontext_t;

#endif
