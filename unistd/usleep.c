#include <unistd.h>
#include <time.h>			// for nanosleep()

int usleep(useconds_t usecs)
{
	struct timespec ts;
	int rc;

	ts.tv_sec = (usecs / 1000000UL);
	ts.tv_nsec = (usecs % 1000000UL) * 1000UL;

	rc = nanosleep(&ts, NULL);
	return rc;
}
