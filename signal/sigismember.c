#include "libc/signal.h"
#include <errno.h>
#include "libc/cdefs.h"

// FIXME: sigaddset, sigdelset & sigismember:
//        use macro to manipulate the sigset

int sigismember(const sigset_t * set, int sig)
{
	size_t w, b;
	unsigned long res;

	if (__unlikely(!valid_signal(sig))) {
		errno = EINVAL;
		return -1;
	}

	sig--;
	w = sig / (sizeof(long) * 8);
	b = sig % (sizeof(long) * 8);

	res = set->__sig[w] & (1UL << b);

	return (res != 0);
}
