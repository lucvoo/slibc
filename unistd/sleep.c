#include <unistd.h>
#include <time.h>

unsigned int sleep(unsigned int seconds)
{
	struct timespec ts;
	int rc;

	ts.tv_sec = seconds;
	ts.tv_nsec = 0;

	// FIXME: possible problem with SIGCHLD: see glibc
	rc = nanosleep(&ts, &ts);
	if (rc != 0)			// was interrupted
		return ts.tv_sec + (ts.tv_nsec >= 500000000L);
	else
		return rc;
}
