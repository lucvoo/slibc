#include <netdb.h>
#include <stdio.h>

int main(void)
{
	struct protoent *ent;
	char **list;

	while ((ent = getprotoent())) {
		printf("%s\t%d", ent->p_name, ent->p_proto);
		list = ent->p_aliases;
		if (*list) {
			printf("\t%s", *list);
			for (list++; *list; list++)
				printf(" %s", *list);
		}
		printf("\n");
		fflush(stdout);
	}

	return 0;
}
