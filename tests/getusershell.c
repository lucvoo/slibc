#include <unistd.h>
#include <stdio.h>

int main(void)
{
	const char *ptr;

	while ((ptr = getusershell())) {
		printf("shell: '%s'\n", ptr);
	}

	return 0;
}
