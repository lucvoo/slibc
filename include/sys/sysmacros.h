#ifndef _SYS_SYSMACROS_H
#define _SYS_SYSMACROS_H

// WARNING: will change in 2.6 ??
//
#define major(DEV)		((DEV) >> 8)
#define minor(DEV)		((DEV) & 0xff)
#define makedev(MAJ, MIN)	((dev_t) (((MAJ) << 8)|(MIN)))

#endif
