#ifndef _LIBC_ROUND_H
#define _LIBC_ROUND_H

#define	ROUND_UP(X, N)	(((X) + (N) - 1) & ~((N) - 1))

#endif
