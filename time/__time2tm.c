#include "libc/time.h"

// convert a time_t value to the corresponding struct tm value

// day in preceding months
static const int daysmonth_ny[12] = { 0,
	31,
	31 + 28,			// non-leap year
	31 + 28 + 31,
	31 + 28 + 31 + 30,
	31 + 28 + 31 + 30 + 31,
	31 + 28 + 31 + 30 + 31 + 30,
	31 + 28 + 31 + 30 + 31 + 30 + 31,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
	31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30,
};
static const int monthdays_ny[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

static const int daysmonth_ly[12] = { 0,
	31,
	31 + 29,			// leap year
	31 + 29 + 31,
	31 + 29 + 31 + 30,
	31 + 29 + 31 + 30 + 31,
	31 + 29 + 31 + 30 + 31 + 30,
	31 + 29 + 31 + 30 + 31 + 30 + 31,
	31 + 29 + 31 + 30 + 31 + 30 + 31 + 31,
	31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30,
	31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
	31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30,
};
static const int monthdays_ly[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

static inline void adjust_mday(struct tm *tm, time_t yday, int leap)
{
	const int *daysmonth = leap ? daysmonth_ly : daysmonth_ny;
	const int *monthdays = leap ? monthdays_ly : monthdays_ny;
	int month;
	int mday;

	// month approximation
	month = yday / 30;

	while (1) {
		mday = 1 + yday - daysmonth[month];
		if (__unlikely(mday <= 0))
			month--;
		else if (__unlikely(mday > monthdays[month]))
			month++;
		else
			break;
	}

	tm->tm_mon = month;
	tm->tm_mday = mday;
}

void __libc_time2tm(struct tm *tm, time_t t)
{
	int year;
	int yday;
	int leap;

	tm->tm_sec = t % 60;
	t /= 60;
	tm->tm_min = t % 60;
	t /= 60;
	tm->tm_hour = t % 24;
	t /= 24;

	// now 't is the number of day since the epoch
	tm->tm_wday = (t + 4) % 7;

	// calculate a first approximation of the year;
	year = (4 * t) / (4 * 365 + 1);

	while (1) {
		// use the same formula than mktime() shifted by 70
		leap = (year + 1) / 4;
		leap -= (year + 69) / 100;
		leap += (year + 369) / 400;

		yday = t - (year * 365 + leap);
		if (yday < 0)		// year was overestimated
		{
			year--;
			continue;
		}
		if (yday > 366)		// year was underestimated
		{
			year++;
			continue;
		}
		// FIXME: recheck here ?? use __time2tm() ???
		break;
	}

	tm->tm_year = year + 70;
	tm->tm_yday = yday;

	adjust_mday(tm, yday, __isleap(year + 1970));
}
