#include <stdlib.h>
#include <string.h>			// for memcmp()
#include <fcntl.h>			// for open()
#include <errno.h>			// for itself
#include "libc/cdefs.h"

// FIXME: use base64 mapping ??

static
const char map[64] = "azertyuiopqsdfghjklmwxcvbn" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "0123456789" "_-";

static unsigned int idx;

static inline unsigned int next_state(void)
{
	return idx = idx * 1103515245U + 12345U;
}

static void init_state(void) __attribute((constructor));
	 static void init_state(void)
{
	idx = getpid();
}

int mkstemp(char *template)
{
	int saved_errno;
	size_t len;
	char *ptr;

	len = strlen(template);
	ptr = template + (len - 6);
	if (__unlikely((len < 6) || memcmp(ptr, "XXXXXX", 6) != 0)) {
		errno = EINVAL;
		return -1;
	}

	saved_errno = errno;
	while (1) {
		unsigned int tmp;
		int fd;
		int i;

		// generate a new name;
		tmp = next_state();
		for (i = 5; i >= 0; i--) {
			ptr[i] = map[tmp % 64];
			tmp /= 64;
		}

		// and try it
		fd = open(template, O_CREAT | O_RDWR | O_EXCL | O_NOFOLLOW, 0600);
		if (fd >= 0) {
			errno = saved_errno;
			return fd;
		}
		if (errno != EEXIST)
			return -1;
	}
	// Can't find a unique filename
	// we are retrying the same names
}
