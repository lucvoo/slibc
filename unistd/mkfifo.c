#include <sys/stat.h>

int mkfifo(const char *pathname, mode_t mode)
{
	int rc;

	rc = mknod(pathname, mode | S_IFIFO, 0);
	return rc;
}
