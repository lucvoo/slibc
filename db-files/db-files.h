#ifndef _LIBC_DBFILES_H
#define _LIBC_DBFILES_H

// parse lib: parse mmapped text with \n terminated lines

// mostly stolen from dietlibc

#include <sys/types.h>

typedef struct {
	const char *buf;
	const char *ptr;
	const char *end;
} parse_state_t;

// open and mmap file, fill in parse_state_t
int __libc_parse_start(const char *filename, parse_state_t * s);
// unmap file
void __libc_parse_finish(parse_state_t * s);

#define COPYstr(dst, sep)				\
	dst = bptr;					\
	if (pptr < pend)				\
	{   while ((*pptr != sep) && (*pptr != '\n') && (bptr < bend)) \
		*bptr++ = *pptr++;			\
	    pptr++;					\
	    *bptr++ = '\0';				\
	} else goto error

#define COPYul(dst, sep)				\
	if (pptr < pend)				\
	{   unsigned long l;				\
	    for (l=0; isdigit(*pptr); pptr++)		\
		l = l*10 + *pptr - '0';			\
	    pptr++;					\
	    dst = l;					\
	} else goto error

#include <ctype.h>
#define COPYstr_ws(dst)					\
	dst = bptr;					\
	if (pptr < pend)				\
	{   while (!isspace(*pptr) && (bptr < bend))	\
		*bptr++ = *pptr++;			\
	    while (isspace(*pptr))			\
		pptr++;					\
	    *bptr++ = '\0';				\
	} else goto error

#define COPYul_ws(dst)					\
	if (pptr < pend)				\
	{   unsigned long l;				\
	    for (l=0; isdigit(*pptr); pptr++)		\
		l = l*10 + *pptr - '0';			\
	    pptr++;					\
	    dst = l;					\
	    while (isspace(*pptr))			\
		pptr++;					\
	} else goto error

#include <stdint.h>
#define SET_ALIGN(DEST, SRC)				\
	{   uintptr_t ptr, msk;				\
							\
	    ptr = (uintptr_t) SRC;			\
	    msk = sizeof(DEST[0]) -1;			\
	    ptr += msk;					\
	    ptr &= ~msk;				\
	    DEST = (__typeof__(DEST)) ptr;		\
	}

#endif
