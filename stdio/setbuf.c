#include <stdio.h>

void setbuf(FILE * restrict S, char *restrict buf)
{
	setvbuf(S, buf, buf ? _IOFBF : _IONBF, BUFSIZ);
}
