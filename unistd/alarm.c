#include <unistd.h>
#include <sys/time.h>

unsigned int alarm(unsigned int secs)
{
	struct itimerval old, new;
	unsigned int retval;

	new.it_value.tv_usec = 0;
	new.it_interval.tv_sec = 0;
	new.it_interval.tv_usec = 0;
	new.it_value.tv_sec = (long int)secs;

	if (setitimer(ITIMER_REAL, &new, &old) < 0)
		return 0;

	retval = old.it_value.tv_sec;
	if (old.it_value.tv_usec)
		++retval;

	return retval;
}
