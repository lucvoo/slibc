#include <strings.h>
#include <ctype.h>

int strcasecmp(const char *s1, const char *s2)
{
	unsigned int c2;
	unsigned int c1;

	do {
		if (_isupper(c1 = *s1++))
			c1 = _tolower(c1);
		if (_isupper(c2 = *s2++))
			c2 = _tolower(c2);
	} while (c1 == c2 && c1);

	return c1 - c2;
}
