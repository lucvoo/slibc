#include "libc/stdio.h"

int feof(FILE * S)
{
	return S->flags & SF_EOF;
}
