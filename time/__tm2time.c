#include "libc/time.h"

static
const int __spm[12] = { 0,
	(31),
	(31 + 28),
	(31 + 28 + 31),
	(31 + 28 + 31 + 30),
	(31 + 28 + 31 + 30 + 31),
	(31 + 28 + 31 + 30 + 31 + 30),
	(31 + 28 + 31 + 30 + 31 + 30 + 31),
	(31 + 28 + 31 + 30 + 31 + 30 + 31 + 31),
	(31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30),
	(31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31),
	(31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30),
};

static const int __dim0[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static const int __dim1[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

time_t __libc_tm2time(struct tm *tm)
{
	time_t t;
	int year = tm->tm_year;
	int leap;
	int days;
	const int *dim;

start:
	if (year < 70)
		return -1;
	if (tm->tm_mon < 0 || tm->tm_mon >= 12)
		return -1;
	if (tm->tm_mday < 1 || tm->tm_mday > 31)
		return -1;

	// calculate day of year, ignore leap years
	days = __spm[tm->tm_mon] + tm->tm_mday - 1;
	if (__isleap(year + 1900) && tm->tm_mon >= 2)
		days++;

	tm->tm_yday = days;

	// compensate for leap years
	leap = (year - 69) / 4;
	leap -= (year - 1) / 100;
	leap += (year + 299) / 400;

	t = (year - 70);
	t *= 365;
	t += leap;
	t += days;
	tm->tm_wday = (t + 4) % 7;
	t *= 24;
	t += (tm->tm_hour);
	t *= 60;
	t += (tm->tm_min);
	t *= 60;
	t += (tm->tm_sec);

	// adjust tm_mday & tm_mon
	if (__isleap(year + 1900))
		dim = __dim1;
	else
		dim = __dim0;

	// adjust tm_mday, tm_mon & tm_year
	while (tm->tm_mday > dim[tm->tm_mon]) {
		tm->tm_mday -= dim[tm->tm_mon];
		tm->tm_mon++;

		// adjust tm_year if needed
		if (tm->tm_mon == 12) {
			year++;
			goto start;
		}
	}

	return t;
}
