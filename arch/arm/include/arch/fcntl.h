
// values for 'cmd' in fcntl()
#define F_DUPFD		0		// dup
#define F_GETFD		1		// get close_on_exec
#define F_SETFD		2		// set/clear close_on_exec
#define F_GETFL		3		// get file->f_flags
#define F_SETFL		4		// set file->f_flags
#define F_GETLK		5
#define F_SETLK		6
#define F_SETLKW	7
#define F_SETOWN	8		//  for sockets.
#define F_GETOWN	9		//  for sockets.
#define F_SETSIG	10		//  for sockets.
#define F_GETSIG	11		//  for sockets.

#define F_GETLK64	12		//  using 'struct flock64'
#define F_SETLK64	13
#define F_SETLKW64	14

#define FD_CLOEXEC	1		// actually anything with low bit set goes

// values for 'l_type' used for record locking with fcntl()
// for posix fcntl() and lockf()
#define F_RDLCK		0
#define F_WRLCK		1
#define F_UNLCK		2

/* open/fcntl - O_SYNC is only implemented on blocks devices and
		on files located on an ext2 file system
*/
// file creation flags for open()
#define O_CREAT		   0100		// not fcntl
#define O_EXCL		   0200		// not fcntl
#define O_NOCTTY	   0400		// not fcntl
#define O_TRUNC		  01000		// not fcntl

// file status flags for open() and fcntl()
#define O_APPEND	  02000
#define O_NONBLOCK	  04000
#define O_SYNC		 010000
#define O_DSYNC		O_SYNC		// kludge!
#define O_RSYNC		O_SYNC		// kludge!

// FIXME: compatibility ...
#define O_NDELAY	O_NONBLOCK
#define FASYNC		 020000		// fcntl, for BSD compatibility

// mask for use with file access modes
#define O_ACCMODE	     03

// file access modes for open() and fcntl()
#define O_RDONLY	     00
#define O_WRONLY	     01
#define O_RDWR		     02

// linux specific stuff
#define O_DIRECT	 040000		// direct disk access hint - currently ignored
#define O_NOFOLLOW	0100000		// don't follow links
#define O_DIRECTORY	0200000		// must be a directory
#define O_LARGEFILE	0400000

#if 0
// for old implementation of bsd flock ()
#define F_EXLCK		4		// or 3
#define F_SHLCK		8		// or 4

// for leases
#define F_INPROGRESS	16

// operations for bsd flock(), also used by the kernel implementation
#define LOCK_SH		1		// shared lock
#define LOCK_EX		2		// exclusive lock
#define LOCK_NB		4		/* or'd with one of the above to prevent
					   blocking */
#define LOCK_UN		8		// remove lock

#define LOCK_MAND	32		// This is a mandatory flock
#define LOCK_READ	64		// ... Which allows concurrent read operations
#define LOCK_WRITE	128		// ... Which allows concurrent write operations
#define LOCK_RW		192		// ... Which allows concurrent read & write ops

#define F_ULOCK 0			// Unlock a previously locked region. 
#define F_LOCK  1			// Lock a region for exclusive use. 
#define F_TLOCK 2			// Test and lock a region for exclusive use. 
#define F_TEST  3			// Test a region for other processes locks. 

#if !defined(O_ASYNC) && defined(FASYNC)
#define O_ASYNC FASYNC
#endif

#endif

#include "arch-generic/fcntl.h"
