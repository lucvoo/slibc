#include <stdio.h>

int getw(FILE * S)
{
	int w;

	fread(&w, sizeof(w), 1, S);

	if (ferror(S))
		return EOF;

	return w;
}

#include "libc/link_warning.h"
warn_legacy(getw, "fread");
