#include <time.h>
#include "libc/time.h"

struct tm *localtime(const time_t * timep)
{
	static struct tm tm;

	return localtime_r(timep, &tm);
}
