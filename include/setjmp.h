#ifndef _SETJMP_H
#define _SETJMP_H

#include <sys/cdefs.h>

#include "arch/setjmp.h"		// for type __jmp_buf
#include "types/sigset_t.h"		// FIXME: namespace violation

typedef struct {
	__jmp_buf __jmpbuf;		// Calling environment. 
	sigset_t __mask;		// Saved signal mask. 
	int __saved;			// Saved the signal mask? 
} jmp_buf[1];

typedef jmp_buf sigjmp_buf;

void longjmp(jmp_buf env, int val) __NORETURN;
	 void siglongjmp(sigjmp_buf env, int val) __NORETURN;
	 void _longjmp(jmp_buf env, int val) __NORETURN;

	 int setjmp(jmp_buf env);
	 int sigsetjmp(sigjmp_buf env, int save);
	 int _setjmp(jmp_buf env);

#define  setjmp(env)		sigsetjmp(env, 1)
#define _setjmp(env)		sigsetjmp(env, 0)

#endif
