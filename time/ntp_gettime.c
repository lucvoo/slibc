#include <sys/timex.h>

int ntp_gettime(struct ntptimeval *ntv)
{
	struct timex tx;
	int rc;

	tx.modes = 0;			// not an update
	rc = adjtimex(&tx);

	ntv->time = tx.time;
	ntv->maxerror = tx.maxerror;
	ntv->esterror = tx.esterror;

	return rc;
}
