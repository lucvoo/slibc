#include <ctype.h>

// FIXME: work by table --> easier for locales

int toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return c - 'a' + 'A';
	else
		return c;
}
