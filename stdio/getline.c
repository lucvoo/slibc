#include <stdio.h>

ssize_t getline(char **restrict linep, size_t * restrict np, FILE * restrict S)
{
	return getdelim(linep, np, '\n', S);
}
