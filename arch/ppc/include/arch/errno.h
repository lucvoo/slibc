#ifndef _ARCH_ERRNO_H
#define _ARCH_ERRNO_H

#include "arch-generic/errno.h"

#undef  EDEADLOCK
#define EDEADLOCK       58      // File locking deadlock error

#define ECANCELED	125	// Operation Canceled
#define ENOKEY		126	// Required key not available
#define EKEYEXPIRED	127	// Key has expired
#define EKEYREVOKED	128	// Key has been revoked
#define EKEYREJECTED	129	// Key was rejected by service

#endif
