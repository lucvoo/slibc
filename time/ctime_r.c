#include <time.h>

char *ctime_r(const time_t * tp, char *buf)
{
	struct tm tm;

	localtime_r(tp, &tm);
	return asctime_r(&tm, buf);
}
