#include <stdlib.h>

int abs(int i)
{
	if (i < 0)
		i = -i;

	return i;
}

#include <limits.h>

#if LONG_BIT == WORD_BIT
long labs(long) __attribute__ ((alias("abs")));
#endif
