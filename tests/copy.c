#include <stdio.h>

int main(void)
{
	FILE *fr;
	FILE *fw;
	int c;

	fr = fopen("/bin/tar", "r");
	fw = fopen("/tmp/zz", "w");
	if (!fr || !fw)
		return 1;

	while ((c = fgetc(fr)) != EOF)
		fputc(c, fw);

//    remove("/tmp/zz");
	return 0;
}
