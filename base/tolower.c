#include <ctype.h>

// FIXME: work by table --> easier for locales

int tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		return c - 'A' + 'a';
	else
		return c;
}
