#include <ulimit.h>
#include <sys/resource.h>
#include <stdarg.h>
#include <errno.h>
#include <limits.h>

long ulimit(int cmd, ...)
{
	struct rlimit limit;

	switch (cmd) {
	case UL_GETFSIZE:
		if (getrlimit(RLIMIT_FSIZE, &limit) != 0)
			return -1;

		return limit.rlim_cur / 512;

	case UL_SETFSIZE:
		{
			va_list ap;
			rlim_t nlimit;

			va_start(ap, cmd);
			nlimit = (rlim_t) va_arg(ap, long);
			va_end(ap);

			if (nlimit > (RLIM_INFINITY / 512))
				nlimit = RLIM_INFINITY / 512;

			limit.rlim_cur = nlimit * 512;
			limit.rlim_max = nlimit * 512;

			if (setrlimit(RLIMIT_FSIZE, &limit))
				return -1;

			return nlimit;
		}
		break;

	case __UL_GETOPENMAX:		// FIXME: used by configure!!!
		return OPEN_MAX;

	default:
		errno = EINVAL;
		return -1;
	}
}
