#include <ctype.h>

#undef	islower

int islower(int c)
{
	return __ctype[(c) + 1] & _ISlower;
}
