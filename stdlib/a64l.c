#include <stdlib.h>

#define OFFSET		'.'
#define NO		0xff

static
const unsigned char table[] = {
	0, 1,
	2, 3, 4, 5, 6, 7, 8, 9, 10, 11, NO, NO, NO, NO, NO, NO,
	NO, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
	27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, NO, NO, NO, NO, NO,
	NO, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52,
	53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63
};

long a64l(const char *str)
{
	unsigned long res = 0;
	unsigned int shift = 0;

	do {
		unsigned int idx;
		unsigned long val;

		idx = *str++ - OFFSET;
		if (idx >= sizeof(table))
			break;

		val = table[idx];
		if (val == NO)
			break;

		res |= val << shift;
		shift += 6;
	} while (shift < 36);

	return res;
}
