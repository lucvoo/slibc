#include <signal.h>

int sigpause(int sig)
{
	sigset_t set;
	int rc;

	if (sigprocmask(SIG_BLOCK, NULL, &set) < 0)
		return -1;

	if (sigdelset(&set, sig) < 0)
		return -1;

	rc = sigsuspend(&set);
	return rc;
}
