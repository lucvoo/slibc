#include <sys/wait.h>

int waitpid(pid_t pid, int *status, int options)
{
	return wait4(pid, status, options, NULL);
}
