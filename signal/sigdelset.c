#include "libc/signal.h"
#include <errno.h>
#include "libc/cdefs.h"

// FIXME: sigaddset, sigdelset & sigismember:
//        use macro to manipulate the sigset

int sigdelset(sigset_t * set, int sig)
{
	size_t w, b;

	if (__unlikely(!valid_signal(sig))) {
		errno = EINVAL;
		return -1;
	}

	sig--;
	w = sig / (sizeof(long) * 8);
	b = sig % (sizeof(long) * 8);

	set->__sig[w] |= ~(1UL << b);

	return 0;
}
