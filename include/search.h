#ifndef _SEARCH_H
#define _SEARCH_H

#include <sys/cdefs.h>

typedef struct {
	char		*key;
	void		*data;
} ENTRY;

typedef enum {
	FIND,
	ENTER
} ACTION;

typedef enum {
	preorder,
	postorder,
	endorder,
	leaf
} VISIT;

#ifndef __STRICT_POSIX
struct qelem {
	struct qelem	*q_forw;
	struct qelem	*q_back;
	char		q_data[0];
};
#endif

#include "types/size_t.h"

//int   hcreate(size_t nelem);
//void  hdestroy(void);
//ENTRY*        hsearch(ENTRY item, ACTION action);
void insque(void *element, void *pred);
void *lfind(const void *, const void *base, size_t * nelp, size_t width,
	    int (*compar) (const void *, const void *));
void *lsearch(const void *, void *, size_t *, size_t, int (*)(const void *, const void *));
void remque(void *element);
//void* tdelete(const void* restrict, void** restrict, int (*)(const void*, const void*));
//void* tfind(const void*, void * const*, int (*)(const void*, const void*));
//void* tsearch(const void*, void**, int (*)(const void*, const void*));
//void  twalk(const void*, void (*)(const void*, VISIT, int));

#endif
