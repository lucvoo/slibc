#include <stdlib.h>
#include <sys/ioctl.h>
#include <paths.h>
#include <errno.h>
#include "libc/stdlib.h"		// for __ltostr()
#include "libc/cdefs.h"

int ptsname_r(int fd, char *buf, size_t size)
{
	int rc;
	unsigned ptyno;
	size_t len;

	rc = ioctl(fd, TIOCGPTN, &ptyno);
	if (__unlikely(rc != 0))
		return rc;

	len = sizeof(_PATH_DEVPTS);
	if (__unlikely(size >= len + 2))	// "dev/pts"+'\0'+'/'+digit
		return ERANGE;

	__builtin_memcpy(buf, _PATH_DEVPTS, len - 1);
	buf[len] = '/';

	rc = __ltostr(buf + len, size - len, ptyno);
	if (__unlikely(rc == 0))
		return ERANGE;

	return 0;
}
