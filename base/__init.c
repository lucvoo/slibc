#include <stdlib.h>			// for exit()
#include <unistd.h>			// for _exit()
#include "libc/symbols.h"

typedef void (*fn_t) (void);

// FIXME: can be avoided if put in a separate file + weak do_ctors() !
// for the creation of at least one entry
static
fn_t __CTOR_LIST__[0] __attribute__ ((section(".ctors")));

static					//inline
void do_ctors(void)
{
	fn_t *f = &__CTOR_LIST__[0];

	while (*f) {
		(*f) ();
		f++;
	}
}

char **__environ = NULL;
weak_alias(__environ, environ);

const char *__progname_full = "";
extern int main(int argc, char **argv, char **envp);

__NORETURN void __libc_init(uintptr_t * stack, void (*onexit) (void));
__NORETURN void __libc_init(uintptr_t * stack, void (*onexit) (void))
{
	int argc;
	char **argv;
	char **envp;
	int rc;

	(void)onexit;			// not used

	argc = *stack++;
	argv = (void *)stack;
	envp = argv + (argc + 1);

	__progname_full = argv[0];
	__environ = envp;

	do_ctors();

	rc = main(argc, argv, envp);

	exit(rc);
}
