#include <strings.h>
#include <string.h>
#include <limits.h>

int ffs(int i)
{
	int bit = 0;
	int shift = WORD_BIT / 2;
	unsigned int mask = UINT_MAX >> shift;

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
