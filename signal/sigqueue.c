#include <signal.h>
#include <string.h>

#if 0
int sigqueue(pid_t pid, int sig, const union sigval val)
{
	siginfo_t info;

	memset(&info, 0, sizeof(siginfo_t));

	info.si_signo = sig;
	info.si_code = SI_QUEUE;
	info.si_pid = getpid();
	info.si_uid = getuid();
	info.si_value = val;

	return __sys_rt_sigqueueinfo(pid, sig, &info);
}
#endif
