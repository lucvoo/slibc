#include <termios.h>
#include <sys/ioctl.h>

int tcflush(int fd, int queue_selector)
{
	return ioctl(fd, TCFLSH, queue_selector);
}
