#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

long long int strtoll(const char *restrict ptr, char **restrict endptr, int base)
{
	int neg = 0;
	unsigned long long int v;
	int saved_errno = errno;

	while (isspace(*ptr))
		ptr++;

	if (*ptr == '-') {
		neg = 1;
		ptr++;
	}

	v = strtoull(ptr, endptr, base);
	if (v > (unsigned long long)LLONG_MAX) {
		if ((long long)v == LLONG_MIN && neg) {
			errno = saved_errno;
			return v;
		}

		errno = ERANGE;
		return (neg ? LLONG_MIN : LLONG_MAX);
	}

	if (neg)
		v = -v;

	return v;
}

#include <inttypes.h>
intmax_t strtoimax(const char *restrict, char **restrict, int) __attribute__ ((alias("strtoll")));
