#include <stdlib.h>

// FIXME: check for overflow ???
double strtod(const char *restrict str, char **restrict endptr)
{
	return strtold(str, endptr);
}
