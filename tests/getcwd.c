#include <unistd.h>
#include <stdio.h>

static char buf[4096];

int main(void)
{
	char *ptr;

	ptr = getcwd(buf, sizeof(buf));
	if (ptr) {
		printf("CWD='%s'\n", ptr);

		return 0;
	} else {
		puts("getcwd: error");
		return 1;
	}
}
