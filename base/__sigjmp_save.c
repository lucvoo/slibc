#include <setjmp.h>
#include <signal.h>

int __libc_sigjmp_save(sigjmp_buf env, int savemask);

int __libc_sigjmp_save(sigjmp_buf env, int savemask)
{
	int saved;

	saved = (sigprocmask(SIG_BLOCK, NULL, &env[0].__mask) == 0);
	env[0].__saved = (savemask && saved);

	return 0;
}
