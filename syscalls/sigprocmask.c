#include <signal.h>
#include "libc/syscall.h"

static inline syscall4(int, rt_sigprocmask, int, const sigset_t *, sigset_t *, size_t)

	 int sigprocmask(int how, const sigset_t * set, sigset_t * oset)
{
	return rt_sigprocmask(how, set, oset, sizeof(sigset_t));
}
