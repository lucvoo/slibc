#include <unistd.h>
#include <sys/utsname.h>
#include <string.h>
#include <errno.h>
#include "libc/cdefs.h"

//@ return -EINVAL if the buffer is too short

int getdomainname(char *name, size_t size)
{
	struct utsname uts;
	size_t len;
	int rc;

	rc = uname(&uts);
	if (__unlikely(rc != 0))
		return -1;

	len = strlen(uts.domainname);
	if (len >= size) {
		errno = EINVAL;
		return -1;
	}

	memcpy(name, uts.domainname, len + 1);

	return 0;
}
