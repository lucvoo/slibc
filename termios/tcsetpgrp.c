#include <unistd.h>
#include <sys/ioctl.h>

int tcsetpgrp(int fd, pid_t pid)
{
	return ioctl(fd, TIOCSPGRP, &pid);
}
