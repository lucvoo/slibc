#include <stdlib.h>

lldiv_t lldiv(long long n, long long d)
{
	lldiv_t res;

	res.quot = n / d;
	res.rem = n - (res.quot * d);

	return res;
}

#include <inttypes.h>
#include "libc/symbols.h"
imaxdiv_t imaxdiv(intmax_t n, intmax_t d) __alias(lldiv);

#include <limits.h>
#include "libc/symbols.h"
#if LONG_BIT == __LLONG_BIT
	 ldiv_t ldiv(long, long)__alias(lldiv);
#endif
