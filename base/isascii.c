#include <ctype.h>

#undef	isascii

int isascii(int c)
{
	return __ctype[c + 1] & _ISascii;
}
