#include <ctype.h>

#undef	isalnum

int isalnum(int c)
{
	return __ctype[(c) + 1] & _ISalnum;
}
