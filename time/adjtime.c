#include <sys/time.h>
#include <sys/timex.h>

int adjtime(const struct timeval *ntv, struct timeval *otv)
{
	struct timex tx;
	int rc;

	if (ntv) {
		tx.offset = ntv->tv_sec * 1000000L + ntv->tv_usec;
		tx.modes = ADJ_OFFSET_SINGLESHOT;
	} else
		tx.modes = 0;

	rc = adjtimex(&tx);
	if (rc)
		return -1;

	if (otv) {
		// FIXME: what if tx.offset is negative ???
		//        modulo is "round to zero" in C99
		otv->tv_usec = tx.offset % 1000000;
		otv->tv_sec = tx.offset / 1000000;

		// FIXME: can tv_usec be negative ???
	}

	return 0;
}
