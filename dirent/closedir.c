#include "libc/dirent.h"
#include <stdlib.h>			// for free()
#include <unistd.h>			// for close()

int closedir(DIR * d)
{
	int rc;

	rc = close(d->fd);
	free(d);

	return rc;
}
