#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *ptr;

	ptr = malloc(3);
	if (!ptr) {
		perror("malloc() failed");
		exit(1);
	}

	return 0;
}
