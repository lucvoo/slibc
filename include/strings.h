#ifndef _STRINGS_H
#define _STRINGS_H

/*	sub includes */
#include <sys/cdefs.h>
#include "types/size_t.h"

/*	Functions prototypes */
char *index(const char *s, int c) __PURE;
	 char *rindex(const char *s, int c) __PURE;
	 int bcmp(const void *s1, const void *s2, size_t count);
	 int ffs(int i) __CONST;
	 int strcasecmp(const char *s1, const char *s2) __PURE;
	 int strncasecmp(const char *s1, const char *s2, size_t n) __PURE;
	 void bcopy(const void *src, void *dest, size_t count);
	 void bzero(void *dest, size_t count);

#endif
