#ifndef _SYS_SELECT_H
#define _SYS_SELECT_H

#include <time.h>			// For struct timespec
#include <sys/time.h>			// For struct timeval

// Constant & Macros definitions
#define FD_SETSIZE	1024
#define __NFDBITS	(8 * sizeof(unsigned long))
#define __FDSET_LONGS	(FD_SETSIZE/__NFDBITS)
#define __FDWORD(fd)	((fd) / __NFDBITS)
#define __FDBIT(fd)	(1UL << ((fd) % __NFDBITS))

#define FD_CLR(fd, S)	\
  do { fd_set* s=S; s->bits[__FDWORD(fd)] &= ~__FDBIT(fd); } while (0)
#define FD_ISSET(fd, S)	\
  ({ fd_set* s=S; s->bits[__FDWORD(fd)] & __FDBIT(fd); })
#define FD_SET(fd, S)	\
  do { fd_set* s=S; s->bits[__FDWORD(fd)] &= __FDBIT(fd); } while (0)
#define FD_ZERO(S)	\
  do { fd_set* s=S; __builtin_memset(s, 0, sizeof(fd_set)); } while (0)

#include "types/sigset_t.h"

typedef struct {
	unsigned long bits[__FDSET_LONGS];
} fd_set;

int select(int, fd_set * restrict rfds,
	   fd_set * restrict wfds, fd_set * restrict xfds, struct timeval *restrict timeout);

int pselect(int, fd_set * restrict rfds,
	    fd_set * restrict wfds,
	    fd_set * restrict xfds,
	    const struct timespec *restrict timeout, const sigset_t * restrict sigmask);

#endif
