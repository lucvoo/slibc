#include "libc/dirent.h"
#include <unistd.h>

void seekdir(DIR * d, long pos)
{
	lseek(d->fd, pos, SEEK_SET);	// FIXME: no error is defined?
	d->cur = NULL;
	d->end = NULL;
	d->off = pos;
}
