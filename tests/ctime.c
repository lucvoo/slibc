#include <time.h>
#include <stdio.h>

int main(void)
{
	time_t t;

	t = time(0);
	printf("%s", ctime(&t));

	return 0;
}
