#include <signal.h>
#include "libc/syscall.h"

static inline syscall3(long, rt_sigqueueinfo, pid_t, int, siginfo_t *)

	 int __sys_rt_sigqueueinfo(pid_t pid, int sig, siginfo_t * info)
{
	return rt_sigqueueinfo(pid, sig, info);
}
