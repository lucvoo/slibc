#include <stdio.h>

extern const char *__progname_full;
extern const char *__progname;

int main(void)
{
	printf("__progname_full = '%s'\n", __progname_full);
	printf("__progname      = '%s'\n", __progname);

	return 0;
}
