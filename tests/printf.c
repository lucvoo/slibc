#include <stdio.h>

int main(void)
{
	int i;

	printf("%04o'\n", 0774);
	printf("%04lo'\n", 0774L);
	printf("\n");

	for (i = 0; i > -1; i = 10 * i + 1) {
		printf("%d'\n", i);
		printf("%0d'\n", i);
		printf("%-d'\n", i);
		printf("%+d'\n", i);
		printf("% d'\n", i);

		printf("%6d'\n", i);
		printf("%06d'\n", i);
		printf("%-6d'\n", i);
		printf("%+6d'\n", i);
		printf("% 6d'\n", i);
	}

	return 0;
}
