#include <stdlib.h>
#include <paths.h>			// for _PATH_DEVPTMX
#include <fcntl.h>			// for open()

int posix_openpt(int oflag)
{
	int rc;

	rc = open(_PATH_DEVPTMX, oflag);
	return rc;
}
