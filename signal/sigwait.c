#include <signal.h>
#include <errno.h>
#include "libc/cdefs.h"

int sigwait(const sigset_t * restrict set, int *restrict ptr)
{
	int sig;

	sig = sigtimedwait(set, 0, 0);
	if (__unlikely(sig == -1))
		return errno;

	*ptr = sig;
	return 0;
}
