#include <time.h>
#include "libc/time.h"

struct tm *gmtime_r(const time_t * timep, struct tm *tm)
{
	__libc_time2tm(tm, *timep);

	return tm;
}
