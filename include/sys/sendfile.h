#ifndef _SYS_SENDFILE_H
#define _SYS_SENDFILE_H

#include "types/off_t.h"
#include "types/size_t.h"
#include "types/ssize_t.h"

ssize_t sendfile(int out_fd, int in_fd, off_t * offset, size_t count);
ssize_t sendfile64(int out_fd, int in_fd, loff_t * offset, size_t count);

#endif
