#include <sys/mntent.h>
#include <stdio.h>

FILE *setmntent(const char *pathname, const char *type)
{
	return fopen(pathname, type);
}
