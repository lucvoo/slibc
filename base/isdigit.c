#include <ctype.h>

#undef	isdigit

int isdigit(int c)
{
	return __ctype[c + 1] & _ISdigit;
}
