#include <sys/mntent.h>
#include <stdio.h>
#include <stdlib.h>

static int show(const char *file)
{
	struct mntent *me;
	FILE *f = fopen(file, "r");

	if (!f) {
		perror("fopen() failed()");
		exit(1);
	}

	printf("\nin %s:\n", file);
	while ((me = getmntent(f))) {
		printf("%s\t%s\t%s\t%s\t%d\t%d\n",
		       me->mnt_fsname, me->mnt_dir, me->mnt_type,
		       me->mnt_opts, me->mnt_freq, me->mnt_passno);
	}

	return 0;
}

int main(void)
{
	show("/etc/fstab");
	show("/etc/mtab");

	return 0;
}
