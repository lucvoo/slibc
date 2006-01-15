#include "libc/dirent.h"

int dirfd(DIR * dirp)
{
	return dirp->fd;
}
