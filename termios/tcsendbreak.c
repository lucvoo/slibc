#include <termios.h>
#include <sys/ioctl.h>

int tcsendbreak(int fd, int duration)
{					// FIXME: what to do with duration argument to icoctl ???
	return ioctl(fd, TCSBRKP, duration);
}
