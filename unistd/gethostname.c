#include <unistd.h>
#include <sys/utsname.h>
#include <string.h>

int gethostname(char *name, size_t len)
{
	struct utsname u;
	int rc;

	rc = uname(&u);
	if (!rc)
		return rc;

	strncpy(name, u.nodename, len);

	return 0;
}
