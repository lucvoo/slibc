#include <termios.h>
#include <sys/ioctl.h>
#include <errno.h>

int tcsetattr(int fd, int action, const struct termios *t)
{
	int request;

	switch (action) {
	case TCSANOW:
		request = TCSETS;
		break;
	case TCSADRAIN:
		request = TCSETSW;
		break;
	case TCSAFLUSH:
		request = TCSETSF;
		break;
	default:
		errno = EINVAL;
		return -1;
	}

	return ioctl(fd, request, t);
}
