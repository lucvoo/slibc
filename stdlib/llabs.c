#include <stdlib.h>

long long llabs(long long i)
{
	if (i < 0)
		i = -i;

	return i;
}

#include <inttypes.h>
intmax_t imaxabs(intmax_t) __attribute__ ((alias("llabs")));

#include <limits.h>

#if LONG_BIT == __LLONG_BIT
long labs(long) __attribute__ ((alias("llabs")));
#endif
