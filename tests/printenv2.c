#include <unistd.h>
#include <string.h>

int main(int argc, char **argv, char **envp)
{

	// suppress compiler complaints
	(void)argc;
	(void)argv;

	for (; *envp; envp++) {
		write(1, *envp, strlen(*envp));
		write(1, "\n", 1);
	}

	return 0;
}
