#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pid_t parent_pid;
pid_t child_pid;

int main(void)
{

	parent_pid = getpid();
	printf("Parent PID=%d\n", parent_pid);
	if (fork() == 0) {
		child_pid = getpid();
		printf("Child PID=%d\n", child_pid);
		return 0;
	}
	sleep(1);
	return 0;
}
