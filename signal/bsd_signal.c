#include <signal.h>

__sig_t bsd_signal(int sig, __sig_t handler)
{
	struct sigaction nact, oact;

	nact.sa_handler = handler;
	nact.sa_flags = SA_RESTART;
	sigemptyset(&nact.sa_mask);
	sigaddset(&nact.sa_mask, sig);

	if (sigaction(sig, &nact, &oact) == -1)
		return SIG_ERR;

	return oact.sa_handler;
}
