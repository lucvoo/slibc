#include <unistd.h>
#include <string.h>

const char usage[] = "usage: execve <executable path>\n";
const char msg_err[] = "execve failed!\n";

int main(int argc, const char *argv[])
{
	int rc;
	const char *ex_argv[] = { 0, "a", "b", "c", 0 };
	const char *ex_envp[] = { "A=a", "B=b", 0 };

	if (argc != 2) {
		write(2, usage, sizeof(usage));
		return 1;
	}

	ex_argv[0] = argv[1];
	rc = execve(argv[1], (char **)ex_argv, (char **)ex_envp);
	if (rc)
		write(2, msg_err, sizeof(msg_err));

	return rc;
}
