#ifndef _SYS_IOCTL_H
#define _SYS_IOCTL_H

// SuS want this in <stropts.h> ...

#include "asm/ioctl.h"
#include "asm/ioctls.h"

int ioctl(int fd, int request, ...);

#endif
