#ifndef _LIBC_STDIO_H
#define _LIBC_STDIO_H

#include <stdio.h>
#include "types/pid_t.h"

// values for flags
#define SF_ERROR	1
#define SF_EOF		2
#define SF_RD		4
#define SF_WR		8
#define SF_WRITING	16
#define SF_BUFBLCK	32		// buffering: block
#define SF_BUFLINE	64		// buffering: line
#define SF_BUFNONE	128		// buffering: none
#define SF_BUFMSK	(SF_BUFBLCK|SF_BUFLINE|SF_BUFNONE)
#define SF_USERBUF	256		// user supplied buffer
#define SF_STDFILE	512		// one of the predefined FILE
#define SF_ISPIPE	1024

#define SF_ERR		(SF_ERROR|SF_EOF)

// values for internal fopen()
#define O__RDONLY	1
#define O__WRONLY	2

struct __stdio_file {
	int		fd;
	unsigned int	flags;
	char		*ptr;		// position in the buffer
	char		*base;		// start of the buffer
	char		*endr;		// end of the read buffer
	char		*endw;		// end of the write buffer
	size_t		size;		// size of the buffer
	unsigned char	pushbuf;	// buffer for ungetc
	unsigned int	pushed;		// flag for ungetc
	FILE		*next;		// linked list
	pid_t		pid;		// child pid for popen()
};

// Globals definitions
extern FILE *__stdio_flist;

#define for_each_file(S) for (S=__stdio_flist; S; S=S->next)

static inline void insert_entry(FILE * S)
{
	S->next = __stdio_flist;
	__stdio_flist = S;
}

static inline void remove_entry(FILE * S)
{
	FILE *P;

	if (__stdio_flist == S) {
		__stdio_flist = S->next;
		return;
	}

	for_each_file(P) {
		if (P->next == S) {
			P->next = S->next;
			break;
		}
	}
}

static inline FILE * __stdio_init(FILE * S, int fd, unsigned int flags)
{
	S->fd = fd;
	S->flags = flags;

	insert_entry(S);

	return S;
}

// some macros
#include "libc/cdefs.h"
#define CHECK_FILE(S)	do { if (__unlikely(S->flags & SF_ERR)) \
				 return EOF;			\
			} while (0)

int __stdio_flshbuf(FILE * S);
int __stdio_fillbuf(FILE * S);
int __stdio_flush_stdin(void);
int __stdio_flush_stdout(void);
int __stdio_flush_stderr(void);
int __stdio_getmode(const char *mode, unsigned *of, unsigned *sf);
int __stdio_fputx(FILE * S, const char *src, size_t size);
FILE *__stdio_new(void);
void __stdio_cleanup(void);

#endif
