#include <ctype.h>

#undef	isgraph

int isgraph(int c)
{
	return __ctype[(c) + 1] & _ISgraph;
}
