#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	char tmpl[] = "/tmp/zz-XXXXXX";
	int i;

	for (i = 0; i < 1000; i++) {
		int fd;

		strcpy(tmpl, "/tmp/zz-XXXXXX");
		fd = mkstemp(tmpl);
		if (fd == -1) {
			perror("mkstemp() failed");
			exit(1);
		}
//      printf("=> '%s'\n", tmpl);
		close(fd);
	}

	return 0;
}
