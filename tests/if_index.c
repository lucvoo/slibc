#include <stdio.h>
#include <net/if.h>

const char *tbl[] = {
	"lo",
	"eth0",
	"eth1",
	"foo",
	"azertyuiopqsdfghjklm",
};

#define max	(sizeof(tbl)/sizeof(tbl[0]))

int main(void)
{
	unsigned int index;
	unsigned int i;

	for (i = 0; i < max; i++) {
		index = if_nametoindex(tbl[i]);
		printf("%s\t=> %d\n", tbl[i], index);
	}

	return 0;
}
