#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

long int strtol(const char *restrict ptr, char **restrict endptr, int base)
{
	int neg = 0;
	unsigned long int v;
	int saved_errno = errno;

	while (isspace(*ptr))
		ptr++;

	if (*ptr == '-') {
		neg = 1;
		ptr++;
	}

	v = strtoul(ptr, endptr, base);
	if (v > (unsigned long)LONG_MAX) {
		if ((long)v == LONG_MIN && neg) {
			errno = saved_errno;
			return v;
		}

		errno = ERANGE;
		return (neg ? LONG_MIN : LONG_MAX);
	}

	if (neg)
		v = -v;

	return v;
}
