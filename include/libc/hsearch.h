#ifndef _LIBC_HSEARCH_
#define _LIBC_HSEARCH_

#include <search.h>

struct hentry {
	size_t		size;
	ENTRY		list[0];
};

struct htable {
	size_t		size;
	size_t		nelem;
	struct hentry	*entries;
};

#endif
