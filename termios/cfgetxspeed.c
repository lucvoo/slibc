#include <termios.h>
#include "libc/symbols.h"

static
speed_t cfgetxspeed(const struct termios *tp)
{
	return tp->c_cflag & (CBAUD | CBAUDEX);
}

strong_alias(cfgetxspeed, cfgetispeed);
strong_alias(cfgetxspeed, cfgetospeed);
