#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char buff[32];
	int rc;

	rc = ptsname_r(0, buff, sizeof(buff));
	if (rc) {
		perror("ptsname_r() failed");
		exit(1);
	}

	printf("ptsname -> '%s'\n", buff);

	return 0;
}
