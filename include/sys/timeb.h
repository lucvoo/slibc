#ifndef _SYS_TIMEB_H
#define _SYS_TIMEB_H

#include "types/time_t.h"

struct timeb {
	time_t		time;
	unsigned short	millitm;
	short		timezone;
	short		dstflag;
};

int ftime(struct timeb *t);

#endif
