#ifndef _ULIMIT_H
#define _ULIMIT_H

// symbolic values for cmd argument of ulimit()
#define UL_GETFSIZE	0
#define UL_SETFSIZE	1

#define __UL_GETOPENMAX	4		// FIXME: configure use this!

long ulimit(int cmd, ...);

#endif
