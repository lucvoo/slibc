#include <unistd.h>

int setpgrp(void)
{
	int rc;

	rc = setpgid(0, 0);
	return rc;
}
