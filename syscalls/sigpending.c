#include <signal.h>
#include "libc/syscall.h"

static inline syscall2(int, rt_sigpending, sigset_t *, size_t)

	 int sigpending(sigset_t * set)
{
	return rt_sigpending(set, sizeof(sigset_t));
}
