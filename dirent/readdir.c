#include "libc/dirent.h"
#include "libc/cdefs.h"
#include <values/NULL.h>

struct dirent *readdir(DIR * d)
{
	struct dirent *de;

	// fill buffer if necessary
	if (d->cur >= d->end) {
		int nb;

		nb = __sys_getdents(d->fd, (void *)d->buf, sizeof(d->buf));
		if (__unlikely(nb <= 0))	// EOF or error
		{
			d->cur = d->end = NULL;
			return NULL;
		}

		d->cur = d->buf;
		d->end = d->buf + nb;
	}

	de = d->cur;
	d->off = de->d_off;
	d->cur += de->d_reclen;

	return de;
}
