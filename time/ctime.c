#include <time.h>

char *ctime(const time_t * timep)
{
	struct tm *tm;

	tm = localtime(timep);
	return asctime(tm);
}
