#include "libc/stdio.h"

void rewind(FILE * S)
{
	fseek(S, 0, SEEK_SET);
	S->flags &= ~(SF_EOF | SF_ERR);
}
