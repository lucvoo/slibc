#include <arpa/inet.h>
#include "libc/stdlib.h"		// for __ltostr()

char *inet_ntoa_r(struct in_addr addr, char *buf)
{
	unsigned char *a;
	unsigned int n;
	unsigned int len;
	char *ptr;
	int i;

	a = (unsigned char *)&addr.s_addr;
	ptr = buf;
	for (len = 16, i = 0; i < 4; i++) {
		n = __ltostr(ptr, len, a[i]);
		ptr[n] = '.';
		ptr += n + 1;
		len -= n + 1;
	}
	ptr[-1] = '\0';			// undo the last '.'

	return buf;
}
