#include <stdio.h>

int vsprintf(char *restrict s, const char *restrict fmt, va_list ap)
{
	return vsnprintf(s, 1 << 30, fmt, ap);
	// FIXME: kludge^^^^^
}

#include "libc/link_warning.h"
warn_unbounded(vsprintf, "vsnprintf()");
