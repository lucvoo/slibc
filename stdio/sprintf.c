#include <stdio.h>
#include <stdarg.h>

int sprintf(char *restrict s, const char *restrict fmt, ...)
{
	va_list ap;
	int n;

	va_start(ap, fmt);
	n = vsnprintf(s, 1 << 30, fmt, ap);
	va_end(ap);

	return n;
}

#include "libc/link_warning.h"
warn_unbounded(sprintf, "snprintf()");
