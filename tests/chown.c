#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	const char *f = "zz.chown";
	struct stat bef, aft;

	if (creat(f, 0600) < 0)
		exit(1);
	if (stat(f, &bef) < 0)
		exit(1);
	if (chown(f, (uid_t) - 1, (gid_t) - 1) == -1)
		exit(1);
	if (stat(f, &aft) < 0)
		exit(1);

	if (bef.st_uid == aft.st_uid && bef.st_gid == aft.st_gid)
		return 0;

	exit(1);
}
