#include <unistd.h>
#include <sys/time.h>

useconds_t ualarm(useconds_t value, useconds_t interval)
{
	struct itimerval new, old;

	new.it_value.tv_sec = 0;
	new.it_value.tv_usec = value;
	new.it_interval.tv_sec = 0;
	new.it_interval.tv_usec = interval;

	if (setitimer(ITIMER_REAL, &new, &old) < 0)
		return -1;

	return old.it_value.tv_sec * 1000000 + old.it_value.tv_usec;
}
