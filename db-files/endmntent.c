#include <sys/mntent.h>
#include <stdio.h>

int endmntent(FILE * S)
{
	fclose(S);
	return 1;
}
