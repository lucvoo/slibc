#include <utime.h>
#include "libc/syscall.h"

// we prefer to emulate sys_utime with sys_utimes if it exist
#ifndef __NR_utimes

syscall2(int, utime, const char *, const struct utimbuf *)
#else

#include <sys/time.h>

int utime(const char *path, const struct utimbuf *times)
{
	struct timeval tv[2], *ptr;

	if (times) {
		tv[0].tv_usec = 0;
		tv[1].tv_usec = 0;
		tv[0].tv_sec = times->actime;
		tv[1].tv_sec = times->modtime;
		ptr = tv;
	} else
		ptr = NULL;

	return utimes(path, ptr);
}
#endif
