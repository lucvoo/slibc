#ifndef _ARCH_TYPES_SIGSET_T_H
#define _ARCH_TYPES_SIGSET_T_H

typedef struct {
	unsigned long __sig[64/(8*sizeof(long))];
} sigset_t;

#endif
