#include <time.h>
#include "libc/time.h"

struct tm *gmtime(const time_t * timep)
{
	static struct tm tm;

	__libc_time2tm(&tm, *timep);

	return &tm;
}
