#include <signal.h>

int sigignore(int sig)
{
	struct sigaction act;
	int rc;

	act.sa_handler = SIG_IGN;
	if (sigemptyset(&act.sa_mask) < 0)
		return -1;

	act.sa_flags = 0;

	rc = sigaction(sig, &act, NULL);
	return rc;
}
