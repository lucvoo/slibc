#include <unistd.h>

int execv(const char *path, char *const argv[])
{
	int rc;

	rc = execve(path, argv, environ);
	return rc;
}
