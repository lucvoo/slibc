#include <unistd.h>
#include <stdio.h>

extern char **environ;

int main(void)
{
	char **envp;

	for (envp = environ; *envp; envp++) {
		puts(*envp);
	}

	return 0;
}
