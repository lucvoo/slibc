#ifndef _PTY_H
#define _PTY_H

#include <termios.h>

int forkpty(int *master, char *name, struct termios *tp, struct winsize *wp);
int getpt(void);
int login_tty(int fd);
int openpty(int *master, int *slave, char *name, struct termios *tp, struct winsize *wp);

#endif
