#ifndef _SYS_POLL_H
#define _SYS_POLL_H

#include "arch/poll.h"

struct pollfd {
	int		fd;		// file descriptor
	short		events;		// requested events
	short		revents;	// returned events
};

typedef unsigned int nfds_t;

int poll(struct pollfd *ufds, nfds_t nfds, int timeout);

#endif
