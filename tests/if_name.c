#include <stdio.h>
#include <net/if.h>

int main(void)
{
	char buf[IF_NAMESIZE];
	char *name;
	int i;

	for (i = 0; i < 4; i++) {
		name = if_indextoname(i, buf);
		if (!name)
			continue;
		printf("if[%d] = '%s'\n", i, name);
	}

	return 0;
}
