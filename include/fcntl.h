#ifndef _FCNTL_H
#define _FCNTL_H

#include <sys/cdefs.h>
#include <sys/stat.h>
#include <unistd.h>

#include "types/mode_t.h"
#include "types/off_t.h"
#include "types/pid_t.h"

#include "arch/fcntl.h"

int creat(const char *pathname, mode_t mode);
int fcntl(int fd, int cmd, ...);
int open(const char *pathname, int flags, ...);

#endif
