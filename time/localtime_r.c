#include <time.h>
#include "libc/time.h"

struct tm *localtime_r(const time_t * timep, struct tm *tm)
{

// FIXME: FIXME: FIXME: FIXME: FIXME: FIXME: FIXME: FIXME: FIXME:

	__libc_time2tm(tm, *timep + 2 * 60 * 60);

// FIXME: FIXME: FIXME: FIXME: FIXME: FIXME: FIXME: FIXME: FIXME:

	return tm;
}
