#include <string.h>
#include "libc/symbols.h"

// FIXME: locale

int strcoll(const char *s1, const char *s2)
{
	int rc;

	rc = strcmp(s1, s2);
	return rc;
}
