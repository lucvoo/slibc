#ifndef _SYS_UIO_H
#define _SYS_UIO_H

#include "types/size_t.h"
#include "types/ssize_t.h"

struct iovec {
	void		*iov_base;	// Starting address
	size_t		iov_len;	// Length in bytes 
};

ssize_t readv(int fd, const struct iovec *vector, int count);
ssize_t writev(int fd, const struct iovec *vector, int count);

#endif
