#include <arpa/inet.h>

static char buf[16];

char *inet_ntoa(struct in_addr addr)
{
	return inet_ntoa_r(addr, buf);
}
