#include <stdlib.h>
#include <pty.h>
#include <paths.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>

// WARNING: will only work on a /dev/ptmx enabled kernel
//          (OK with devpts or devfs)
int openpty(int *master, int *slave, char *name, struct termios *tp, struct winsize *wp)
{
	char path[32];
	int fd_m, fd_s;
	int lock;
	int rc;

	fd_m = open(_PATH_DEVPTMX, O_RDWR);
	if (fd_m == -1)
		return fd_m;

	// with UNIX98 ptys: grantpt() is done by the kernel

	// same as unlockpt()
	lock = 0;
	rc = ioctl(fd_m, TIOCSPTLCK, &lock);
	if (rc)
		goto error1;

	// get the path of the slave
	rc = ptsname_r(fd_m, path, sizeof(path));
	if (rc)
		goto error1;

	fd_s = open(path, O_RDWR | O_NOCTTY);
	if (fd_s == -1)
		goto error1;

	if (tp) {
		rc = tcsetattr(fd_s, TCSAFLUSH, tp);
		if (rc)
			goto error2;
	}

	if (wp) {
		rc = ioctl(fd_s, TIOCSWINSZ, wp);
		if (rc)
			goto error2;
	}

	if (name)
		strcpy(name, path);

	*master = fd_m;
	*slave = fd_s;

	return 0;

error2:
	close(fd_s);
error1:
	close(fd_m);
	return -1;
}

#include "libc/link_warning.h"
link_warning(openpty, "openpty()'s ptyname buffer can be unbounded!");
