#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *S;

	S = fopen("zz.z", "w");
	if (!S) {
		perror("fopen() failed!");
		exit(1);
	}

	fputs("abcdefghijklmnopqrstuvwxyz\n", S);
	fprintf(S, "%s:%d\n", __FUNCTION__, __LINE__);

	fclose(S);

	fputs("abcdefghijklmnopqrstuvwxyz\n", stdout);

	return 0;
}
