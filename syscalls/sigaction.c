#include <signal.h>
#include "libc/syscall.h"

typedef struct sigaction sa_t;

static inline syscall4(int, rt_sigaction, int, const sa_t *, sa_t *, size_t)

	 int sigaction(int sig, const sa_t * act, sa_t * oldact)
{
	return rt_sigaction(sig, act, oldact, sizeof(sigset_t));
}
