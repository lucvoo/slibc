#include <signal.h>
#include "libc/syscall.h"

static inline syscall2(int, rt_sigsuspend, const sigset_t *, size_t)

	 int sigsuspend(const sigset_t * newset)
{
	return rt_sigsuspend(newset, sizeof(sigset_t));
}
