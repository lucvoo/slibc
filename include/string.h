#ifndef _STRING_H
#define _STRING_H

#include <sys/cdefs.h>
#include <stddef.h>

// SuS v2 stuff
void *memccpy(void *restrict dest, const void *restrict src, int c, size_t n);
void *memchr(const void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n) __PURE;
void *memcpy(void *restrict dest, const void *restrict src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);
char *strcat(char *restrict dest, const char *restrict src);
char *strchr(const char *s, int c) __PURE;
int strcmp(const char *s1, const char *s2) __PURE;
int strcoll(const char *s1, const char *s2);
char *strcpy(char *restrict dest, const char *restrict src);
size_t strcspn(const char *s, const char *reject);
char *strdup(const char *s) __MALLOC;
char *strerror(int errnum);
int strerror_r(int err, char *buf, size_t n);
size_t strlen(const char *s) __PURE;
char *strncat(char *restrict dest, const char *restrict src, size_t n);
int strncmp(const char *s1, const char *s2, size_t n) __PURE;
char *strncpy(char *restrict dest, const char *restrict src, size_t);
char *strpbrk(const char *s, const char *_accept);
char *strrchr(const char *s, int c) __PURE;
size_t strspn(const char *s, const char *_accept);
char *strstr(const char *haystack, const char *needle) __PURE;
char *strtok(char *restrict s, const char *restrict delim);
char *strtok_r(char *restrict, const char *restrict, char **restrict);
// size_t strxfrm(char* restrict, const char* restrict, size_t);

#ifndef __STRICT_POSIX
// where must we put this one ?
size_t strnlen(const char *s, size_t size) __PURE;

// GNU stuff
int memccmp(const void *s1, const void *s2, int c, size_t n) __PURE;
void *memmem(const void *haystack, size_t haystacklen, const void *needle, size_t needlelen);
char *strsep(char **stringp, const char *delim);
const char *strsignal(int signum);

// BSD stuff
size_t strlcat(char *dst, const char *src, size_t size);
size_t strlcpy(char *dst, const char *src, size_t size);

// ? stuff
char *stpcpy(char *dest, const char *src);
#endif

#endif
