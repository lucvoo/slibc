#ifndef _SYS_TIME_H
#define _SYS_TIME_H

#include <sys/cdefs.h>

#define ITIMER_REAL     0
#define ITIMER_VIRTUAL  1
#define ITIMER_PROF     2

#include "types/time_t.h"
#include "types/suseconds_t.h"

struct timeval;
#include <sys/select.h>

struct timeval {
	time_t		tv_sec;
	suseconds_t	tv_usec;
};

struct itimerval {
	struct timeval	it_interval;	// timer interval
	struct timeval	it_value;	// current value
};

#ifndef __STRICT_POSIX
struct timezone {
	int		tz_minuteswest;	// minutes west of Greenwich
	int		tz_dsttime;	// obsolete!!!
};
#endif

int getitimer(int which, struct itimerval *value);
int gettimeofday(struct timeval *restrict tv, void *restrict tz);
int setitimer(int which, const struct itimerval *restrict value, struct itimerval *restrict ovalue);
int utimes(const char *path, const struct timeval times[2]);

#ifndef __STRICT_POSIX
int settimeofday(const struct timeval *, const struct timezone *);
int adjtime(const struct timeval *ntv, struct timeval *otv);
#endif

#endif
