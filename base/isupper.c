#include <ctype.h>

#undef	isupper

int isupper(int c)
{
	return __ctype[c + 1] & _ISupper;
}
