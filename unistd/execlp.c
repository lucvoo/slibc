#include <unistd.h>
#include <stdarg.h>
#include <alloca.h>

int execlp(const char *file, const char *arg0, ...)
{
	char **argv;
	va_list ap;
	size_t n, N;
	int rc;

	// count the number of arguments
	va_start(ap, arg0);
	N = 1 + 1;			// for arg0 and final NULL
	while (va_arg(ap, const char *))
		     N++;
	va_end(ap);

	// and copy them to a argv array
	argv = alloca(N * sizeof(char *));
	va_start(ap, arg0);
	argv[0] = (char *)arg0;
	for (n = 1; n < N; n++)
		argv[n] = va_arg(ap, char *);

	rc = execvp(file, argv);
	return rc;
}
