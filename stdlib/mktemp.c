#include <stdlib.h>
#include <unistd.h>
#include "libc/cdefs.h"

char *mktemp(char *tmpl)
{
	int fd;

	fd = mkstemp(tmpl);
	if (__unlikely(fd == -1))
		return NULL;

	close(fd);
	return tmpl;
}

#include "libc/link_warning.h"
warn_legacy(mktemp, "mkstemp");
