#include <ctype.h>

#undef	isprint

int isprint(int c)
{
	return __ctype[c + 1] & _ISprint;
}
