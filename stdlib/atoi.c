#include <stdlib.h>
#include <ctype.h>
#include "libc/symbols.h"

int atoi(const char *str)
{
	int val;
	int neg;

	while (isspace(*str))
		str++;

	if (*str == '-') {
		neg = 1;
		str++;
	} else {
		if (*str == '+')
			str++;
		neg = 0;
	}

	val = 0;
	while (1) {
		unsigned int digit;

		digit = (*str - '0');
		if (digit > 10U)
			break;

		str++;
		val = 10 * val + digit;
	}

	if (neg)
		val = -val;

	return val;
}

#include <limits.h>

#if LONG_BIT == WORD_BIT
long atol(const char *) __alias(atoi);
#endif
