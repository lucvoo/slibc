#include <time.h>
#include "libc/time.h"			// for __libc_tm2time()

time_t mktime(struct tm *tm)
{
	time_t t;

	t = __libc_tm2time(tm);

// FIXME: does not take timezone in account !!
// FIXME: does not take saving day light in account !!
// FIXME: does not adjust wday & mon & ...

	tm->tm_wday = 0;
	tm->tm_mon = 0;

	return t;
}
