#include "libc/stdio.h"
#include <unistd.h>			// for pipe, close, exec
#include <stdlib.h>			// for free()
#include <errno.h>
#include "libc/cdefs.h"

static void do_child(int cfd, int rw, const char *cmd) __NORETURN;
	 static void do_child(int cfd, int rw, const char *cmd)
{
	FILE *S;
	int sfd;			// stdin/stdout

	if (rw == SF_RD)
		sfd = STDOUT_FILENO;
	else
		sfd = STDIN_FILENO;

	// redirect the child fd to stdin or stdout
	if (cfd != sfd) {
		dup2(cfd, sfd);		// FIXME: ignore any error ???
		close(cfd);
	}
	// POSIX requirement
	for_each_file(S) {
		if (S->flags & SF_ISPIPE)
			close(S->fd);
	}

	execl("/bin/sh", "sh", "-c", cmd, NULL);
	_exit(127);
}

FILE *popen(const char *cmd, const char *mode)
{
	int pfd, cfd;
	int fds[2];
	int rw;
	pid_t pid;
	FILE *S;

	if ((mode[0] != 'r' && mode[0] != 'w') || mode[0] == '\0' || mode[1] != '\0') {
		errno = EINVAL;
		return NULL;
	}

	S = __stdio_new();
	if (__unlikely(!S))
		return S;

	if (pipe(fds) < 0)
		goto error;

	if (mode[0] == 'r') {
		pfd = fds[0];
		cfd = fds[1];
		rw = SF_RD;
	} else {
		pfd = fds[1];
		cfd = fds[0];
		rw = SF_WR;
	}

	pid = fork();
	if (__unlikely(pid == -1)) {
		close(pfd);
		close(cfd);
		goto error;
	} else if (pid == 0)		// child
	{
		close(pfd);
		do_child(cfd, rw, cmd);

		// never reached
	} else				// pid > 0: parent
	{
		close(cfd);

		S->fd = pfd;
		S->flags = SF_BUFBLCK | SF_ISPIPE | rw;
		insert_entry(S);

		return S;
	}

error:
	free(S->base);
	free(S);

	return NULL;
}
