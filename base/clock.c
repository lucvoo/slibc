#include <time.h>
#include <sys/resource.h>

clock_t clock(void)
{
	struct rusage usage;
	clock_t val;

	getrusage(RUSAGE_SELF, &usage);

	// CLOCKS_PER_SEC always 1000000
	val = usage.ru_utime.tv_sec + usage.ru_stime.tv_sec;
	val *= 1000000;
	val += usage.ru_utime.tv_usec + usage.ru_stime.tv_usec;

	return val;
}
