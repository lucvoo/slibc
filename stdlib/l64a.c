#include <stdlib.h>

static
const char table[] = {
	'.', '/', '0', '1', '2', '3', '4', '5',
	'6', '7', '8', '9', 'A', 'B', 'C', 'D',
	'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
	'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
	'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b',
	'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
	'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
	's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
};

static
char *l64a_r(unsigned long val, char res[7])
{
	int n;

	val &= 0xffffffff;

	for (n = 0; val > 0; n++) {
		res[n] = table[val & 63];
		val /= 64;
	}
	res[n] = 0;

	return res;
}

char *l64a(long val)
{
	static char res[7];

	return l64a_r(val, res);
}
