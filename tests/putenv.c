#include <stdlib.h>

char nameval[] = "CONFTEST_putenv=val";
char name[] = "CONFTEST_putenv";

int main(void)
{
	// Put it in env. 
	if (putenv(nameval))
		exit(1);

	// Try to remove it. 
	if (putenv(name))
		exit(1);

	// Make sure it was deleted. 
	if (getenv(name) != 0)
		exit(1);

	return 0;
}
