#ifndef _SYS_RESOURCE_H
#define _SYS_RESOURCE_H

#include <sys/time.h>
#include "types/id_t.h"

#define PRIO_PROCESS    0
#define PRIO_PGRP       1
#define PRIO_USER       2

#define RUSAGE_SELF     0
#define RUSAGE_CHILDREN (-1)
#define RUSAGE_BOTH     (-2)

#define RLIMIT_CPU	0		// CPU time in ms
#define RLIMIT_FSIZE	1		// Maximum filesize
#define RLIMIT_DATA	2		// max data size
#define RLIMIT_STACK	3		// max stack size
#define RLIMIT_CORE	4		// max core file size
#define RLIMIT_RSS	5		// max resident set size
#define RLIMIT_NPROC	6		// max number of processes
#define RLIMIT_NOFILE	7		// max number of open files
#define RLIMIT_MEMLOCK	8		// max locked-in-memory
#define RLIMIT_AS	9		// address space limit
#define RLIMIT_LOCKS	10		// maximum file locks held

#define RLIM_NLIMITS	11

#define RLIM_INFINITY	(~0UL)
#define RLIM_SAVED_MAX	RLIM_INFINITY
#define RLIM_SAVED_CUR	RLIM_INFINITY

struct rusage {
	struct timeval	ru_utime;	// user time used
	struct timeval	ru_stime;	// system time used
	long		ru_maxrss;	// maximum resident set size
	long		ru_ixrss;	// integral shared memory size
	long		ru_idrss;	// integral unshared data size
	long		ru_isrss;	// integral unshared stack size
	long		ru_minflt;	// page reclaims
	long		ru_majflt;	// page faults
	long		ru_nswap;	// swaps
	long		ru_inblock;	// block input operations
	long		ru_oublock;	// block output operations
	long		ru_msgsnd;	// messages sent
	long		ru_msgrcv;	// messages received
	long		ru_nsignals;	// signals received
	long		ru_nvcsw;	// voluntary context switches
	long		ru_nivcsw;	// involuntary context switches
};

typedef unsigned long rlim_t;

struct rlimit {
	rlim_t		rlim_cur;
	rlim_t		rlim_max;
};

int getpriority(int which, id_t who);
int setpriority(int which, id_t who, int prio);
int getrlimit(int resource, struct rlimit *rlim);
int getrusage(int who, struct rusage *usage);
int setrlimit(int resource, const struct rlimit *rlim);

#endif
