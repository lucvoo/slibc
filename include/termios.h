#ifndef _TERMIOS_H
#define _TERMIOS_H

typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;

#ifndef NCCS
#define NCCS	19
#endif

#include "types/s_termios.h"
#include "arch/termios.h"
#include "types/pid_t.h"

speed_t cfgetispeed(const struct termios *tp);
speed_t cfgetospeed(const struct termios *tp);
int cfsetispeed(struct termios *tp, speed_t speed);
int cfsetospeed(struct termios *tp, speed_t speed);
int tcdrain(int fd);
int tcflow(int fd, int action);
int tcflush(int fd, int queue_selector);
int tcgetattr(int fd, struct termios *tp);
pid_t tcgetsid(int fd);
int tcsendbreak(int fd, int duration);
int tcsetattr(int fd, int action, const struct termios *tp);

#ifndef __STRICT_POSIX
struct winsize {
	unsigned short	ws_row;
	unsigned short	ws_col;
	unsigned short	ws_xpixel;
	unsigned short	ws_ypixel;
};

void cfmakeraw(struct termios *tp);
#endif

#endif
