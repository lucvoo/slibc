#include <setjmp.h>

jmp_buf env;

int foo(void)
{
	if (setjmp(env))
		return 1;
	else
		return 0;
}

void bar(void)
{
	longjmp(env, 3);
}
