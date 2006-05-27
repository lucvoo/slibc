#include <string.h>
#include <limits.h>

int ffsll(long long i)
{
	int bit = 0;
	int shift = __LLONG_BIT / 2;
	unsigned long long mask = ULLONG_MAX >> shift;

	if (!i)
		return 0;

	while (shift) {
		if (!(i & mask)) {
			bit += shift;
			i >>= shift;
		}

		shift /= 2;
		mask >>= shift;
	}

	return bit + 1;
}

#if     __LLONG_BIT == WORD_BIT
#include "libc/symbols.h"
int ffsl(long) __alias(ffsll);
#endif
