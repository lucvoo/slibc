#include <signal.h>
#include "libc/syscall.h"

static inline
syscall4(long, rt_sigtimedwait, const sigset_t *, siginfo_t *, const struct timespec *, size_t)

	 int sigwaitinfo(const sigset_t * set, siginfo_t * info)
{
	int rc;

	rc = rt_sigtimedwait(set, info, NULL, sizeof(sigset_t));
	return rc;
}
