#include <sys/timeb.h>
#include <sys/time.h>			// for gettimeofday()

int ftime(struct timeb *t)
{
	struct timeval tv;
	int rc;

	rc = gettimeofday(&tv, NULL);

	t->time = tv.tv_sec;
	t->millitm = tv.tv_usec / 1000;

	t->timezone = 0;		// SuS say these fields are undefined!
	t->dstflag = 0;

	return rc;
}

#include "libc/link_warning.h"
warn_legacy(ftime, "gettimeofday");
