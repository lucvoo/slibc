#include <stdlib.h>
#include <sys/sysinfo.h>
#include "libc/cdefs.h"

int getloadavg(double loadavg[], int nelem)
{
	struct sysinfo info;
	int i;

	if (__unlikely(nelem < 0))
		goto error;

	if (__unlikely(sysinfo(&info)))
		goto error;

	if (__unlikely(nelem > 3))
		nelem = 3;

	for (i = nelem; --i >= 0;) {
		double load;

		load = info.loads[i];
		loadavg[i] = load / (1 << SI_LOAD_SHIFT);
	}

	return nelem;

error:
	return -1;
}
