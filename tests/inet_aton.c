#include <arpa/inet.h>
#include <stdio.h>

typedef struct {
	int rc;
	uint32_t addr;
	const char *ascii;
} tbl_t;

tbl_t tbl[] = {
	{1, 0xffffffff, "0xffffffff"},
	{1, 0xffffffff, "0xff.0xffffff"},
	{1, 0xffffffff, "0xff.0xff.0xffff"},
	{1, 0xffffffff, "0xff.0xff.0xff.0xff"},
	{1, 0xffffffff, "4294967295"},
	{1, 0xffffffff, "255.16777215"},
	{1, 0xffffffff, "255.255.65535"},
	{1, 0xffffffff, "255.255.255.255"},
	{0, 0xffffffff, "256.255.255.255"},
	{0, 0xffffffff, "255.16777216"},
	{0, 0xffffffff, "255.255.65536"},
	{0, 0xffffffff, "255.255.255.256"},
	{0, 0xffffffff, "255.255.255.255."},
	{0, 0xffffffff, "255.255.255.255 "},

	{1, 0x0, "0.0.0.0"},

	{0, 0, 0}
};

int main(void)
{
	int err = 0;
	tbl_t *p;

	for (p = tbl; p->ascii; p++) {
		struct in_addr a;
		int rc;

		rc = inet_aton(p->ascii, &a);
		if (rc != p->rc) {
			printf("%2d: \"%s\" should return %d\n", p - tbl, p->ascii, p->rc);
			err++;
		} else if (rc == 0)
			continue;
		if (a.s_addr != p->addr) {
			printf("%2d \"%s\" -> %08x not %08x\n", p - tbl, p->ascii, a.s_addr, p->addr);
			err++;
		}
	}

	return err != 0;
}
