#ifndef _LIBC_SIGNAL_H
#define _LIBC_SIGNAL_H

#include <signal.h>

static inline int valid_signal(unsigned int sig)
{
	return (sig > 0) && (sig <= SIGRTMAX);
	// FIXME: why SIGRTMAX and not SIGMAX ???
}

#endif
