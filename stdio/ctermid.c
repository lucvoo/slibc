#include <stdio.h>
#include <string.h>

#define DEV_TTY	"/dev/tty"

static char sbuf[L_ctermid];

char *ctermid(char *buf)
{
	if (!buf)
		buf = sbuf;

	memcpy(buf, DEV_TTY, sizeof(DEV_TTY));

	return buf;
}
