#include <signal.h>

// FIXME: glibc & uClibc differ: some interaction with signal()

int siginterrupt(int sig, int flag)
{
	struct sigaction act;

	sigaction(sig, NULL, &act);

	if (flag)
		act.sa_flags &= ~SA_RESTART;
	else
		act.sa_flags |= SA_RESTART;

	return sigaction(sig, &act, NULL);
}
