#include <pty.h>
#include <unistd.h>

int forkpty(int *master, char *name, struct termios *tp, struct winsize *wp)
{
	int rc;
	int fd_m, fd_s;
	pid_t pid;

	rc = openpty(&fd_m, &fd_s, name, tp, wp);
	if (rc)
		return rc;

	pid = fork();
	if (pid == -1) {
		close(fd_m);
		close(fd_s);

		return pid;
	}

	if (pid == 0)			// child
	{
		close(fd_m);
		if (login_tty(fd_s))
			_exit(1);

		return 0;
	} else				// parent
	{
		*master = fd_m;
		close(fd_s);

		return pid;
	}
}

#include "libc/link_warning.h"
link_warning(forkpty, "forkpty()'s ptyname buffer can be unbounded!");
