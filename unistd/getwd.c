#include <unistd.h>
#include <limits.h>

char *getwd(char *buf)
{
	return getcwd(buf, PATH_MAX);
}

#include "libc/link_warning.h"
warn_legacy(getwd, "getcwd");
