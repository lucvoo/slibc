#include <unistd.h>
#include <string.h>

extern char **environ;

int main(void)
{
	char **envp;

	for (envp = environ; *envp; envp++) {
		write(1, *envp, strlen(*envp));
		write(1, "\n", 1);
	}

	return 0;
}
