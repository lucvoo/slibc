#include <signal.h>

static
__sighandler_t set_mask(int sig, int how, __sighandler_t ret)
{
	sigset_t set;

	// Create an empty signal set. 
	if (sigemptyset(&set) < 0)
		return SIG_ERR;

	// Add the specified signal. 
	if (sigaddset(&set, sig) < 0)
		return SIG_ERR;

	// Add the signal set to the current signal mask. 
	if (sigprocmask(how, &set, NULL) < 0)
		return SIG_ERR;

	return ret;
}

__sighandler_t sigset(int sig, __sighandler_t disp)
{
	struct sigaction nact, oact;

	// Block the signal if needed
	if (disp == SIG_HOLD)
		return set_mask(sig, SIG_BLOCK, SIG_HOLD);

	nact.sa_handler = disp;
	if (sigemptyset(&nact.sa_mask) < 0)
		return SIG_ERR;

	nact.sa_flags = 0;
	if (sigaction(sig, &nact, &oact) < 0)
		return SIG_ERR;

	return set_mask(sig, SIG_UNBLOCK, oact.sa_handler);
}
