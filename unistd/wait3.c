#include <sys/wait.h>

int wait3(int *status, int options, struct rusage *rusage)
{
	return wait4(-1, status, options, rusage);
}
