#include <sys/mntent.h>

struct mntent *getmntent(FILE * fp)
{
	static struct mntent entry;
	static char buf[1024];
	struct mntent *res;

	res = getmntent_r(fp, &entry, buf, sizeof(buf));
	return res;
}
