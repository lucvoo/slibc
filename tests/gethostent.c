#include <netdb.h>
#include <stdio.h>

int main(void)
{
	struct hostent *ent;

	while ((ent = gethostent())) {
		printf("name = '%s'\n", ent->h_name);

		putchar('\n');
	}

	return 0;
}
