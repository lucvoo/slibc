#include "libc/stdio.h"

void clearerr(FILE * S)
{
	S->flags = ~(SF_ERROR | SF_EOF);
}
