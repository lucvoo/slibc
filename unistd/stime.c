#include <time.h>
#include <sys/time.h>
#include <errno.h>
#include "libc/cdefs.h"

int stime(const time_t * t)
{
	struct timeval tv;

	if (__unlikely(!t)) {
		errno = EINVAL;
		return -1;
	}

	tv.tv_sec = *t;
	tv.tv_usec = 0;

	return settimeofday(&tv, NULL);
}
