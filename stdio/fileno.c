#include "libc/stdio.h"

int fileno(FILE * S)
{
	return S->fd;
}
