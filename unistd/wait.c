#include <sys/wait.h>

pid_t wait(int *status)
{
	int rc;

	rc = wait4((pid_t) - 1, status, 0, NULL);
	return rc;
}
