#ifndef _ASM_MMAN_H
#define _ASM_MMAN_H

#define PROT_READ	0x1		// page can be read
#define PROT_WRITE	0x2		// page can be written
#define PROT_EXEC	0x4		// page can be executed
#define PROT_SEM	0x8		// page may be used for atomic ops
#define PROT_NONE	0x0		// page can not be accessed
#define PROT_GROWSDOWN	0x01000000	// mprotect flag: extend change to start of growsdown vma
#define PROT_GROWSUP	0x02000000	// mprotect flag: extend change to end of growsup vma

#define MAP_SHARED	0x01		// Share changes
#define MAP_PRIVATE	0x02		// Changes are private
#define MAP_TYPE	0x0f		// Mask for type of mapping
#define MAP_FIXED	0x10		// Interpret addr exactly
#define MAP_ANONYMOUS	0x20		// don't use a file
#define MAP_RENAME      MAP_ANONYMOUS	// In SunOS terminology
#define MAP_NORESERVE   0x40		// don't reserve swap pages
#define MAP_LOCKED	0x80

#define MAP_GROWSDOWN	0x0100		// stack-like segment
#define MAP_DENYWRITE	0x0800		// ETXTBSY
#define MAP_EXECUTABLE	0x1000		// mark it as an executable
#define MAP_POPULATE	0x8000		// populate (prefault) pagetables
#define MAP_NONBLOCK	0x10000		// do not block on IO

#define MS_ASYNC	1		// sync memory asynchronously
#define MS_INVALIDATE	2		// invalidate the caches
#define MS_SYNC		4		// synchronous memory sync

#define MCL_CURRENT     0x2000		// lock all currently mapped pages
#define MCL_FUTURE      0x4000		// lock all additions to address space

#define POSIX_MADV_NORMAL	0x0	// default page-in behavior
#define POSIX_MADV_RANDOM	0x1	// page-in minimum required
#define POSIX_MADV_SEQUENTIAL	0x2	// read-ahead aggressively
#define POSIX_MADV_WILLNEED	0x3	// pre-fault pages
#define POSIX_MADV_DONTNEED	0x4	// discard these pages

// compatibility flags
#define MAP_ANON	MAP_ANONYMOUS
#define MAP_FILE	0

#endif
