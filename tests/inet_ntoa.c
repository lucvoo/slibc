#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	uint32_t num;
	const char *str;
} tbl_t;

tbl_t tbl[] = {
	{0x00000000, "0.0.0.0"},
	{0x01020304, "1.2.3.4"},
	{0xffffffff, "255.255.255.255"},

	{0x0, 0}
};

int main(void)
{
	int err = 0;
	tbl_t *p;

	for (p = tbl; p->str; p++) {
		char buff[16];
		struct in_addr addr;

		addr.s_addr = htonl(p->num);
		inet_ntoa_r(addr, buff);

		if (strcmp(buff, p->str)) {	//fprintf(stderr, "%08x -> '%s' != '%s'\n", p->num, buff, p->str);
			err++;
		}
	}

	return err != 0;
}
