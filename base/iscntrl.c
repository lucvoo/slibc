#include <ctype.h>

#undef	iscntrl

int iscntrl(int c)
{
	return __ctype[c + 1] & _IScntrl;
}
