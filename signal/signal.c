#include <signal.h>

// sysv emulation

__sig_t signal(int sig, __sig_t handler)
{
	struct sigaction nact, oact;

	nact.sa_handler = handler;
	nact.sa_flags = SA_RESETHAND | SA_NODEFER;
	sigemptyset(&nact.sa_mask);
	sigaddset(&nact.sa_mask, sig);

	if (sigaction(sig, &nact, &oact) == -1)
		return SIG_ERR;

	return oact.sa_handler;
}
