#include <ctype.h>

#undef	isblank

int isblank(int c)
{
	return __ctype[c + 1] & _ISblank;
}
