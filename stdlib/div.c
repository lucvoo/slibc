#include <stdlib.h>

div_t div(int n, int d)
{
	div_t res;

	res.quot = n / d;
	res.rem = n - (res.quot * d);

	return res;
}

#include <limits.h>
#include "libc/symbols.h"

#if LONG_BIT == WORD_BIT
ldiv_t ldiv(long, long)__alias(div);
#endif
