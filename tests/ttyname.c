#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char name[64];
	int rc;

	rc = ttyname_r(0, name, sizeof(name));
	if (rc) {
		perror("ttyname(0) failed");
		exit(1);
	}

	printf("ttyname = '%s'\n", name);

	return 0;
}
