#ifndef _LIBC_DIRENT_H
#define _LIBC_DIRENT_H

#include <dirent.h>
#include <limits.h>			// for PAGE_SIZE

#define sizeof_buf	(PAGE_SIZE - 4*sizeof(void*))
//FIXME: namespace pollution

struct __DIR {
	int		fd;
	void		*end;		// end of valid data in buffer
	void		*cur;		// current position in buffer
	long		off;		// off of current position
	char		buf[sizeof_buf];// buffer of struct dirent
};

#endif
