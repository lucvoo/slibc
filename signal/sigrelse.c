#include <signal.h>

int sigrelse(int sig)
{
	sigset_t set;
	int rc;

	if (sigprocmask(SIG_SETMASK, NULL, &set) < 0)
		return -1;

	if (sigdelset(&set, sig) < 0)
		return -1;

	rc = sigprocmask(SIG_SETMASK, &set, NULL);
	return rc;
}
