#include <stdlib.h>
#include <sys/ioctl.h>

int unlockpt(int fd)
{
	int setlock = 0;
	int rc;

	rc = ioctl(fd, TIOCSPTLCK, &setlock);

	return rc;
}
