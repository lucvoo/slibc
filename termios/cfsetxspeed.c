#include <termios.h>
#include <errno.h>
#include "libc/cdefs.h"
#include "libc/symbols.h"

static
int cfsetxspeed(struct termios *tp, speed_t speed)
{
	if (__unlikely(((speed & ~CBAUD) != 0) && (speed < B57600 || speed > B460800)
	    )) {
		errno = EINVAL;
		return -1;
	}

	tp->c_cflag &= ~(CBAUD | CBAUDEX);
	tp->c_cflag |= speed;

	return 0;
}

strong_alias(cfsetxspeed, cfsetispeed);
strong_alias(cfsetxspeed, cfsetospeed);
