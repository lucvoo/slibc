#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <errno.h>

int isatty(int fd)
{
	pid_t pid;			// dummy one
	int saved;			// saved errno
	int rc;

	saved = errno;
	rc = ioctl(fd, TIOCGPGRP, &pid);
	errno = saved;

	return !rc;
}
