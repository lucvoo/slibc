#include <sys/ipc.h>
#include <sys/stat.h>
#include "libc/cdefs.h"

key_t ftok(const char *path, int id)
{
	struct stat st;
	key_t key;
	int rc;

	rc = stat(path, &st);
	if (__unlikely(rc))
		return -1;

// FIXME: seems kludgy
	key = (st.st_ino << 16) | (st.st_dev << 8) | (id & 0xff);

	return key;
}
