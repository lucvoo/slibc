#include <unistd.h>
#include <sys/ioctl.h>

pid_t tcgetpgrp(int fd)
{
	int pgrp;

	if (ioctl(fd, TIOCGPGRP, &pgrp) == -1)
		return -1;

	return (pid_t) pgrp;
}
