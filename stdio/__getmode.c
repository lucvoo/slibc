#include "libc/stdio.h"
#include <fcntl.h>

#define MODE(A,B,C)	(A|(B<<8)|(C<<16))

int __stdio_getmode(const char *mode, unsigned *oflag, unsigned *sflag)
{
	unsigned m;
	unsigned of;
	unsigned sf;
	int i;

	for (m = 0, i = 0; i < 4; i++) {
		unsigned char c;

		c = mode[i];
		if (c == '\0')
			break;
		m |= c << (i * 8);
	}

	switch (m) {
	case MODE('r', 0, 0):
	case MODE('r', 'b', 0):
		of = O_RDONLY;
		sf = SF_RD;
		break;
	case MODE('r', '+', 0):
	case MODE('r', 'b', '+'):
	case MODE('r', '+', 'b'):
		of = O_RDWR;
		sf = SF_RD | SF_WR;
		break;

	case MODE('w', 0, 0):
	case MODE('w', 'b', 0):
		of = O_WRONLY | O_CREAT | O_TRUNC;
		sf = SF_WR;
		break;
	case MODE('w', '+', 0):
	case MODE('w', 'b', '+'):
	case MODE('w', '+', 'b'):
		of = O_RDWR | O_CREAT | O_TRUNC;
		sf = SF_RD | SF_WR;
		break;

	case MODE('a', 0, 0):
	case MODE('a', 'b', 0):
		of = O_WRONLY | O_CREAT | O_APPEND;
		sf = SF_WR;
		break;
	case MODE('a', '+', 0):
	case MODE('a', 'b', '+'):
	case MODE('a', '+', 'b'):
		of = O_RDWR | O_CREAT | O_APPEND;
		sf = SF_RD | SF_WR;
		break;

	default:
		return -1;
	}

	*oflag = of;
	*sflag = sf;

	return 0;
}
