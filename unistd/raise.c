#include <signal.h>
#include <unistd.h>

int raise(int sig)
{
	int rc;

	rc = kill(getpid(), sig);
	return rc;
}
