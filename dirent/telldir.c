#include "libc/dirent.h"

long telldir(DIR * d)
{
	return d->off;
}
