#include <stdlib.h>

int main(void)
{
	char *ptr;

	ptr = realloc(0, 0);

	return (ptr ? 0 : 1);
}
