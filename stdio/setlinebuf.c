#include <stdio.h>

void setlinebuf(FILE * S)
{
	setvbuf(S, NULL, _IOLBF, 0);
}
