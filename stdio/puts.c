#include "libc/stdio.h"

int puts(const char *s)
{
	int rc;

	rc = fputs(s, stdout);
	if (rc == EOF)
		return rc;
	return fputc('\n', stdout);
}
