#include <ctype.h>

#undef	ispunct

int ispunct(int c)
{
	return __ctype[c + 1] & _ISpunct;
}
