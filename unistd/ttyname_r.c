#include <unistd.h>
#include <errno.h>
#include "libc/stdlib.h"		// for __ltostr()

#define MAX_FD		"4096"

int ttyname_r(int fd, char *name, size_t size)
{
	char self_fd[] = "/proc/self/fd/" MAX_FD;
	char *ptr = self_fd + 14;
	int rc;

	if (!isatty(fd)) {
		errno = ENOTTY;		// not set by isatty() !
		return 0;
	}

	__ltostr(ptr, sizeof(MAX_FD), fd);

	rc = readlink(self_fd, name, size);
	if (rc < 0)
		return -1;

	name[rc] = '\0';

	return 0;
}
