#include <unistd.h>
#include <stdio.h>

gid_t groups[16];

int main(void)
{
	int rc, i;

	rc = getgroups(16, groups);
	if (rc < 0) {
		fprintf(stderr, "rc = %d\n", rc);

		return 1;
	}

	for (i = 0; i < rc; i++)
		printf("groups[%d] = %d\n", i, groups[i]);

	return 0;
}
