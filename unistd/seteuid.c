#include <unistd.h>

int seteuid(uid_t uid)
{
	int rc;

	rc = setreuid((uid_t) - 1, uid);
	return rc;
}
