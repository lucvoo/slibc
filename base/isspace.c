#include <ctype.h>

#undef	isspace

int isspace(int c)
{
	return __ctype[c + 1] & _ISspace;
}
