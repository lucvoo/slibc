#include <locale.h>
#include <values/NULL.h>

char *setlocale(int category, const char *locale)
{
	(void)category;

	if (!locale)
		return (char *)"C";

	// FIXME: unimplemented
	return NULL;
}
