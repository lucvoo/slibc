#ifndef _CTYPE_H
#define _CTYPE_H

#include <sys/cdefs.h>

int isalnum(int c) __CONST;
	 int isalpha(int c) __CONST;
	 int isascii(int c) __CONST;
	 int isblank(int c) __CONST;
	 int iscntrl(int c) __CONST;
	 int isdigit(int c) __CONST;
	 int isgraph(int c) __CONST;
	 int islower(int c) __CONST;
	 int isprint(int c) __CONST;
	 int ispunct(int c) __CONST;
	 int isspace(int c) __CONST;
	 int isupper(int c) __CONST;
	 int isxdigit(int c) __CONST;

	 int toascii(int c) __CONST;
	 int tolower(int c) __CONST;
	 int toupper(int c) __CONST;

// Macro implementation
#define _isupper(c)	(((unsigned int)((c) - 'A')) < 26U)
#define _tolower(c)	((c) | 0x20)
#define _toupper(c)	((c) & ~0x20)

	 enum {
		 _ISalpha = (1 << 0),
		 _ISascii = (1 << 1),
		 _ISblank = (1 << 2),
		 _IScntrl = (1 << 3),
		 _ISdigit = (1 << 4),
		 _ISgraph = (1 << 5),
		 _ISlower = (1 << 6),
		 _ISprint = (1 << 7),
		 _ISpunct = (1 << 8),
		 _ISspace = (1 << 9),
		 _ISupper = (1 << 10),
		 _ISxdigit = (1 << 11),

		 _ISalnum = (_ISalpha | _ISdigit),
	 };

	 extern const unsigned int __ctype[257];
// FIXME: do better!
#define isalnum(c)	(__ctype[(c)+1] & _ISalnum)
#define isalpha(c)	(__ctype[(c)+1] & _ISalpha)
#define isascii(c)	(__ctype[(c)+1] & _ISascii)
#define isblank(c)	(__ctype[(c)+1] & _ISblank)
#define iscntrl(c)	(__ctype[(c)+1] & _IScntrl)
#define isdigit(c)	(__ctype[(c)+1] & _ISdigit)
#define isgraph(c)	(__ctype[(c)+1] & _ISgraph)
#define islower(c)	(__ctype[(c)+1] & _ISlower)
#define isprint(c)	(__ctype[(c)+1] & _ISprint)
#define ispunct(c)	(__ctype[(c)+1] & _ISpunct)
#define isupper(c)	(__ctype[(c)+1] & _ISupper)
#define isspace(c)	(__ctype[(c)+1] & _ISspace)
#define isxdigit(c)	(__ctype[(c)+1] & _ISxdigit)

#endif
