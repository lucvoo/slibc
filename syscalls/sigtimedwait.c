#include <signal.h>
#include "libc/syscall.h"

static inline
syscall4(long, rt_sigtimedwait, const sigset_t *, siginfo_t *, const struct timespec *, size_t)

	 int sigtimedwait(const sigset_t * set, siginfo_t * info, const struct timespec *timeout)
{
	return rt_sigtimedwait(set, info, timeout, sizeof(sigset_t));
}
