#include <stdio.h>

int putw(int w, FILE * S)
{
	int rc;

	rc = fwrite(&w, sizeof(w), 1, S);
	if (rc != 1)
		return EOF;

	return 0;
}

#include "libc/link_warning.h"
warn_legacy(putw, "fwrite");
