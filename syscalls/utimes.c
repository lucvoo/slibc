#include <sys/time.h>
#include "libc/syscall.h"

#ifdef __NR_utimes

syscall2(int, utimes, const char *, const struct timeval *)
#else

#include <utime.h>

int utimes(const char *path, const struct timeval tv[2])
{
	struct utimbuf buf, *ptr;

	if (tv) {
		buf.actime = tv[0].tv_sec;
		buf.modtime = tv[1].tv_sec;
		ptr = &buf;
	} else
		ptr = 0;

	return utime(path, ptr);
}

#endif
