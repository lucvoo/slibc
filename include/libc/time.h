#ifndef _LIBC_TIME_H
#define _LIBC_TIME_H

#include <time.h>
#include "libc/cdefs.h"

void __libc_time2tm(struct tm *tm, time_t t);
time_t __libc_tm2time(struct tm *tm);

static inline int __isleap(int year)
{
	if (__unlikely((year % 400) == 0))
		return 1;
	if (((year % 4) == 0) && ((year % 100) != 0))
		return 1;

	return 0;
}

#endif
