#include <stdlib.h>
#include <paths.h>

char *ptsname(int fd)
{
	static char buf[sizeof(_PATH_DEVPTS) + 10];
	int rc;

	rc = ptsname_r(fd, buf, sizeof(buf));
	if (rc != 0)
		return NULL;

	return buf;
}
