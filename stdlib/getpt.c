#include <stdlib.h>
#include <paths.h>			// for _PATH_DEVPTMX
#include <fcntl.h>			// for open()

int getpt(void)
{
	int fd;

	fd = open(_PATH_DEVPTMX, O_RDWR | O_NOCTTY);
	return fd;
}
