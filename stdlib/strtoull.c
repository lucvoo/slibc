#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include "libc/stdlib.h"

unsigned long long int strtoull(const char *restrict ptr, char **restrict endptr, int _base)
{
	unsigned long long int v;
	int saved_errno = errno;
	unsigned int base = _base;
	unsigned int c;

	while (isspace(*ptr))
		ptr++;

	if (*ptr == '+')
		ptr++;

	if (base == 16 && ptr[0] == '0' && (ptr[1] == 'x' || ptr[1] == 'X'))
		ptr += 2;
	else if (base == 0) {
		if (*ptr == '0') {
			if ((ptr[1] == 'x') || (ptr[1] == 'X')) {
				ptr += 2;
				base = 16;
			} else
				base = 8;
		} else
			base = 10;
	}

	v = 0;
	while ((c = *ptr)) {
		unsigned long long w;

		c = __libc_digit2n(c);
		if (c >= base)
			break;
		if ((w = v * base) < v)	// overflow
		{
			errno = ERANGE;
			return ULLONG_MAX;
		}
		v = w + c;
		ptr++;
	}

	if (endptr)
		*endptr = (char *)ptr;

	// if v==ULONG_MAX, return value is ULLONG_MAX
	// but errno is not set to ERANGE!
	errno = saved_errno;

	return v;
}

#include <inttypes.h>
uintmax_t strtoumax(const char *restrict, char **restrict, int) __attribute__ ((alias("strtoull")));
