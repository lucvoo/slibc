#include <stdlib.h>
#include <sys/ioctl.h>

// Will only work if we run a devpts fs
// where this call is useless!
int grantpt(int fd)
{
	unsigned ptyno;
	int rc;

	// just a check
	rc = ioctl(fd, TIOCGPTN, &ptyno);

	return rc;
}
