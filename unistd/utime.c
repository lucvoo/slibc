#include <utime.h>
#include <sys/time.h>

int utime(const char *path, const struct utimbuf *times)
{
	struct timeval tv[2];
	struct timeval *ptr;

	if (times) {
		tv[0].tv_sec = times->actime;
		tv[0].tv_usec = 0;
		tv[1].tv_sec = times->modtime;
		tv[1].tv_usec = 0;
		ptr = tv;
	} else
		ptr = NULL;

	return utimes(path, ptr);
}
