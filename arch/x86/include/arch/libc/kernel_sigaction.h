#ifndef _KERNEL_SIGNAL_H
#define _KERNEL_SIGNAL_H

#include <signal.h>
#include "types/size_t.h"

int __sys_rt_sigaction(int sig, const struct sigaction *, struct sigaction *, size_t sigsetsize);

#endif
