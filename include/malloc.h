#ifndef _MALLOC_H
#define _MALLOC_H

#include <sys/cdefs.h>
#include <stddef.h>

void *calloc(size_t nmemb, size_t size) __MALLOC;
	 void free(void *ptr);
	 void *malloc(size_t size) __MALLOC;
	 void *realloc(void *ptr, size_t size) __MALLOC;

#endif
