#include <stdio.h>

int main(void)
{
	FILE *fp;
	int c;

	fp = fopen("/usr/share/doc/base-files/copyright", "r");
	if (fp == NULL)
		abort();

	c = getc(fp);
	if (c == EOF)
		abort();

	printf("%ld\n", ftell(fp));

	if (ungetc(c, fp) == EOF)
		abort();

	printf("%ld\n", ftell(fp));

	return 0;
}
