#include <unistd.h>
#include "libc/prototypes.h"

ssize_t __writen(int fd, char *ptr, size_t size)
{
	ssize_t nleft, nwritten;

	nleft = size;
	while (nleft > 0) {
		nwritten = write(fd, ptr, nleft);
		if (nwritten <= 0)
			return nwritten;	// error

		nleft -= nwritten;
		ptr += nwritten;
	}

	return size - nleft;		// FIXME: assert(nleft == 0)
}
