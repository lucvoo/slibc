#include "libc/stdio.h"

int ferror(FILE * S)
{
	return S->flags & SF_ERROR;
}
