#include <setjmp.h>
#include <signal.h>
#include "libc/symbols.h"

void __longjmp(__jmp_buf env, int val) __NORETURN;

	 void siglongjmp(sigjmp_buf env, int val)
{
	if (env[0].__saved)
		sigprocmask(SIG_SETMASK, &(env[0].__mask), NULL);

	if (val == 0)
		val = 1;

	__longjmp(env[0].__jmpbuf, val);
}

weak_alias(siglongjmp, longjmp);
