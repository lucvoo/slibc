#include <unistd.h>

char *ttyname(int fd)
{
	static char name[64];

	if (ttyname_r(fd, name, sizeof(name)))
		return NULL;

	return name;
}
