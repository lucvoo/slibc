#ifndef _CDEFS_H
#define _CDEFS_H

#define __GNUC_VERSION (__GNUC__*100 + __GNUC_MINOR__)

#ifdef __cplusplus
#define __THROW throw ()
#define __BEGIN_DECLS extern "C" {
#define __END_DECLS }
#else
#define __THROW
#define __BEGIN_DECLS
#define __END_DECLS
#endif

#define __CONST		__attribute__((__const__))
#define __MALLOC	__attribute__((__malloc__))
#define __NORETURN	__attribute__((__noreturn__))
#define __PURE		__attribute__((__pure__))

#endif
