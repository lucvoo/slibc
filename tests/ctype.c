#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define ISLOWER(c) ('a' <= (c) && (c) <= 'z')
#define TOUPPER(c) (ISLOWER(c) ? 'A' + ((c) - 'a') : (c))

#define XOR(e, f) (((e) && !(f)) || (!(e) && (f)))

int main(void)
{
	int i;

	for (i = 0; i < 256; i++)
		if (XOR(islower(i), ISLOWER(i)) || toupper(i) != TOUPPER(i)) {
			fprintf(stderr, "error for %02X\n", i);
			exit(2);
		}

	return 0;
}
