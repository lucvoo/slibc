#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int remove(const char *path)
{
	int saved_errno = errno;

	if (unlink(path) == 0)
		return 0;
	else if (errno != EISDIR)
		return -1;

	errno = saved_errno;
	return rmdir(path);
}
