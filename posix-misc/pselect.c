#include <sys/select.h>
#include <signal.h>

int pselect(int nfds, fd_set * rfds, fd_set * wfds, fd_set * xfds,
	    const struct timespec *timeout, const sigset_t * sigmask)
{
	struct timeval tv;
	sigset_t savedmask;
	int rc;

	if (timeout) {
		tv.tv_sec = timeout->tv_sec;
		tv.tv_usec = timeout->tv_nsec;
	}
	// FIXME: the following should be an atomic operation;
	//        need kernel support
	if (sigmask)
		sigprocmask(SIG_SETMASK, sigmask, &savedmask);

	rc = select(nfds, rfds, wfds, xfds, (timeout ? &tv : NULL));

	if (sigmask)
		sigprocmask(SIG_SETMASK, &savedmask, NULL);

	return rc;
}
