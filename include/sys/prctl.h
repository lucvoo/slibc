#ifndef _SYS_PRCTL_H
#define _SYS_PRCTL_H

#include <linux/prctl.h>

int prctl(int option, unsigned long arg2, unsigned long arg3, unsigned long arg4, unsigned long arg5);

#endif
