#include <termios.h>
#include <sys/ioctl.h>

pid_t tcgetsid(int fd)
{
	pid_t sid;
	int rc;

	rc = ioctl(fd, TIOCGSID, &sid);
	if (rc != 0)
		return rc;

	return sid;
}
