#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

int system(const char *cmd)
{
	struct sigaction sa, savintr, savequit;
	sigset_t saveblock;
	pid_t pid;
	int rc;

	if (!cmd)
		return 1;		// a shell is always available

	sa.sa_handler = SIG_IGN;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigemptyset(&savintr.sa_mask);
	sigemptyset(&savequit.sa_mask);
	sigaction(SIGINT, &sa, &savintr);
	sigaction(SIGQUIT, &sa, &savequit);
	sigaddset(&sa.sa_mask, SIGCHLD);
	sigprocmask(SIG_BLOCK, &sa.sa_mask, &saveblock);

	pid = fork();
	if (pid == 0) {
		sigaction(SIGINT, &savintr, NULL);
		sigaction(SIGQUIT, &savequit, NULL);
		sigprocmask(SIG_SETMASK, &saveblock, NULL);
		execl("/bin/sh", "sh", "-c", cmd, NULL);
		_exit(127);
	}
	if (pid == -1) {
		rc = -1;
	} else {
		while (waitpid(pid, &rc, 0) == -1) {
			if (errno != EINTR) {
				rc = -1;
				break;
			}
		}
	}
	sigaction(SIGINT, &savintr, NULL);
	sigaction(SIGQUIT, &savequit, NULL);
	sigprocmask(SIG_SETMASK, &saveblock, NULL);

	return rc;
}
