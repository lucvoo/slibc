#ifndef _SYS_VFS_H
#define _SYS_VFS_H

#include "arch/sys/statfs.h"

int fstatfs(int fd, struct statfs *buf);
int statfs(const char *path, struct statfs *buf);

#endif
