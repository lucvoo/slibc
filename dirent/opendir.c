#include "libc/dirent.h"
#include <fcntl.h>			// for open
#include <stdlib.h>			// for malloc

DIR *opendir(const char *dirname)
{
	DIR *d;
	int fd;
	int rc;

	fd = open(dirname, O_RDONLY | O_DIRECTORY);
	if (fd < 0)
		return NULL;

	rc = fcntl(fd, F_SETFD, FD_CLOEXEC);
	if (rc < 0)
		goto error;

	d = malloc(sizeof(DIR));
	if (!d)
		goto error;

	d->fd = fd;
	d->cur = NULL;
	d->end = NULL;
	d->off = 0;

	return d;

error:
	close(fd);
	return NULL;
}
