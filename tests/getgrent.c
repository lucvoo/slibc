#include <grp.h>
#include <stdio.h>

int main(void)
{
	struct group *grp;
	char **list;

	while ((grp = getgrent())) {
		printf("%s:%s:%u:", grp->gr_name, grp->gr_passwd, grp->gr_gid);
		list = grp->gr_mem;
		if (*list) {
			printf("%s", *list);
			for (list++; *list; list++)
				printf(",%s", *list);
		}
		printf("\n");
	}

	return 0;
}
