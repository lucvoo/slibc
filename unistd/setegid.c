#include <unistd.h>

int setegid(uid_t gid)
{
	int rc;

	rc = setregid((gid_t) - 1, gid);
	return rc;
}
