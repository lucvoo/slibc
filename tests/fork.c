#include <unistd.h>

const char msg_child[] = "child is up!\n";
const char msg_paren[] = "parent still there!\n";
const char msg_error[] = "error occur!\n";

int main(void)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		write(1, msg_error, sizeof(msg_error) - 1);
	else if (pid == 0)
		write(1, msg_child, sizeof(msg_child) - 1);
	else
		write(1, msg_paren, sizeof(msg_paren) - 1);

	return 0;
}
