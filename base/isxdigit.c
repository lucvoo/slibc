#include <ctype.h>

#undef	isxdigit

int isxdigit(int c)
{
	return __ctype[c + 1] & _ISxdigit;
}
