#include <unistd.h>
#include <string.h>

const char msg[] = "Hello, world!\n";

int main(void)
{
	write(1, msg, sizeof(msg) - 1);

	return 0;
}
