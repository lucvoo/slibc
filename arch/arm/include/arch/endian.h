#ifndef _ARCH_ENDIAN_H
#define _ARCH_ENDIAN_H

#define __LITTLE_ENDIAN	1234
#define __BIG_ENDIAN	4321

#ifndef __ARMEB__			// 'normal' little-endian ARM

#define __BYTE_ORDER		__LITTLE_ENDIAN
#define __FLOAT_WORD_ORDER	__LITTLE_ENDIAN
#define __LONG_LONG_PAIR(HI, LO) LO, HI

#else

#define __BYTE_ORDER		__BIG_ENDIAN
#define __FLOAT_WORD_ORDER	__BIG_ENDIAN

#ifdef __ARMWEL__
#define __LONG_LONG_PAIR(HI, LO) LO, HI
#else
#define __LONG_LONG_PAIR(HI, LO) HI, LO
#endif

#endif

#endif
