#include <ctype.h>

#undef	isalpha

int isalpha(int c)
{
	return __ctype[(c) + 1] & _ISalpha;
}
