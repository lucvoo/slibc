#ifndef _SYS_MMAN_H
#define _SYS_MMAN_H

// Constants definitions
#include "arch/sys/mman.h"

#define MAP_FAILED	((void*) -1)

#ifndef __STRICT_POSIX
#define MADV_NORMAL	POSIX_MADV_NORMAL
#define MADV_RANDOM	POSIX_MADV_RANDOM
#define MADV_SEQUENTIAL	POSIX_MADV_SEQUENTIAL
#define MADV_WILLNEED	POSIX_MADV_WILLNEED
#define MADV_DONTNEED	POSIX_MADV_DONTNEED
#endif

#include "arch/types/mode_t.h"
#include "arch/types/off_t.h"
#include "arch/types/size_t.h"

int mlock(const void *addr, size_t len);
int mlockall(int flags);
void *mmap(void *start, size_t length, int prot, int flags, int fd, off_t offset);
int mprotect(void *start, size_t length, int prot);
int msync(void *start, size_t length, int flags);
int munlock(const void *start, size_t length);
int munlockall(void);
int munmap(void *start, size_t length);
int posix_madvise(void *, size_t, int);

#ifndef __STRICT_POSIX
int madvise(void *, size_t, int);
int mincore(void *start, size_t length, unsigned char *vec);
void *mremap(void *, size_t, size_t, unsigned long);
void *mmap2(void *start, size_t length, int prot, int flags, int fd, off_t offset);
#endif

#endif
