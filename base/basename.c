#include <libgen.h>
#include <string.h>
#include <stdio.h>
#include "libc/cdefs.h"

char *basename(char *pathname)
{
	static char dotbuf[2];
	size_t n;
	char *ptr;

	if (__unlikely(!pathname || pathname[0] == '\0')) {
		dotbuf[0] = '.';
		dotbuf[1] = '\0';
		return dotbuf;
	}

	n = strlen(pathname);
	while (n && pathname[n - 1] == '/')	// strip trailing '/'
		n--;
	pathname[n] = '\0';

	if (!(ptr = strrchr(pathname, '/'))) {
		ptr = pathname;
	} else if (ptr[0] != '\0')
		ptr++;

	if (ptr[0] == '\0') {
		ptr[0] = '/';
		ptr[1] = '\0';
	}

	return ptr;
}
