#include <netdb.h>
#include <stdio.h>

int main(void)
{
	struct servent *srv;
	char **list;

	while ((srv = getservent())) {
		printf("%-8s\t%d/%s", srv->s_name, srv->s_port, srv->s_proto);
		list = srv->s_aliases;
		if (*list) {
			printf("\t\t%s", *list);
			for (list++; *list; list++)
				printf(" %s", *list);
		}
		printf("\n");
		fflush(stdout);
	}

	return 0;
}
