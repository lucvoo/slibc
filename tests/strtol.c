#include <stdlib.h>
#include <stdio.h>

static char line[4096];

int main(void)
{
	while (fgets(line, sizeof(line), stdin)) {
		long val;

		val = strtol(line, 0, 10);
		printf("%ld\n", val);
	}

	return 0;
}
