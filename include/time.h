#ifndef _TIME_H
#define _TIME_H

#include <sys/cdefs.h>

#include "values/NULL.h"
#define CLOCKS_PER_SEC	1000000

#include "types/clock_t.h"
#include "types/time_t.h"
#include "types/size_t.h"

struct tm {
	int		tm_sec;
	int		tm_min;
	int		tm_hour;
	int		tm_mday;
	int		tm_mon;
	int		tm_year;
	int		tm_wday;
	int		tm_yday;
	int		tm_isdst;
	long		tm_gmtoff;			// seconds east of UTC!
//    const char*       tm_zone;
};

struct timespec {
	time_t		tv_sec;
	long		tv_nsec;
};

struct itimerspec {
	struct timespec	it_interval;
	struct timespec	it_value;
};

// Variables declarations
extern int daylight;
extern long timezone;
extern char *tzname[];

char *asctime(const struct tm *tm);
char *asctime_r(const struct tm *restrict tm, char *restrict buf);
clock_t clock(void);
char *ctime(const time_t * timep);
char *ctime_r(const time_t * timep, char *buf);
double difftime(time_t time1, time_t time0);
//struct tm* getdate(const char* string);
struct tm *gmtime(const time_t * timep);
struct tm *gmtime_r(const time_t * restrict timep, struct tm *restrict result);
struct tm *localtime(const time_t * timep);
struct tm *localtime_r(const time_t * restrict timep, struct tm *restrict result);
time_t mktime(struct tm *tm);
int nanosleep(const struct timespec *req, struct timespec *rem);
size_t strftime(char *restrict, size_t max, const char *restrict, const struct tm *restrict);
char *strptime(const char *restrict buf, const char *restrict format, struct tm *restrict tm);
time_t time(time_t * t);
//void  tzset(void);

#ifndef __STRICT_POSIX
int stime(const time_t * t);
#endif

#endif
