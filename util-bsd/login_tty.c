#include <pty.h>
#include <sys/ioctl.h>
#include <unistd.h>

int login_tty(int fd)
{
	int rc;

	setsid();

	rc = ioctl(fd, TIOCSCTTY, (void *)0);
	if (rc == -1)
		return rc;

	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);
	if (fd > 2)
		close(fd);

	return 0;
}
