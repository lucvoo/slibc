#include <sys/time.h>
#include <time.h>

time_t time(time_t * t)
{
	struct timeval tv;
	time_t res;

	if (gettimeofday(&tv, NULL))
		res = (time_t) - 1;
	else
		res = (time_t) tv.tv_sec;	// FIXME: is this right

	if (t)
		*t = res;

	return res;
}
