#ifndef _SCHED_H
#define _SCHED_H

#include <time.h>			// for struct timespec

#define SCHED_FIFO	1
#define SCHED_OTHER	0
#define SCHED_RR	2

#include "types/pid_t.h"

struct sched_param {
	int	sched_priority;
};

int sched_get_priority_max(int policy);
int sched_get_priority_min(int policy);
int sched_getparam(pid_t, struct sched_param *);
int sched_getscheduler(pid_t);
int sched_rr_get_interval(pid_t, struct timespec *);
int sched_setparam(pid_t, const struct sched_param *);
int sched_setscheduler(pid_t, int, const struct sched_param *);
int sched_yield(void);

#ifndef __STRICT_POSIX
int sched_setaffinity(pid_t, unsigned int, const unsigned long *);
int sched_getaffinity(pid_t, unsigned int, unsigned long *);
#endif

#endif
