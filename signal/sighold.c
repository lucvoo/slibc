#include <signal.h>

int sighold(int sig)
{
	sigset_t set;
	int rc;

	if (sigprocmask(SIG_SETMASK, NULL, &set) < 0)
		return -1;

	if (sigaddset(&set, sig) < 0)
		return -1;

	rc = sigprocmask(SIG_SETMASK, &set, NULL);
	return rc;
}
