#include <stdlib.h>
#include <unistd.h>
#include "libc/symbols.h"
#include "libc/stdio.h"
#include "libc/atexit.h"

static
void dummy(void)
{
	return;
}

extern int __libc_atexit_cleanup(void) __weak(dummy);
	 extern void __stdio_cleanup(void) __weak(dummy);
	 extern int __stdio_flush_stdin(void) __weak(dummy);
	 extern int __stdio_flush_stdout(void) __weak(dummy);
	 extern int __stdio_flush_stderr(void) __weak(dummy);

	 void exit(int status)
{
	(void)dummy;

	__libc_atexit_cleanup();

	__stdio_cleanup();
	__stdio_flush_stdin();		// FIXME: sensical ???
	__stdio_flush_stdout();
	__stdio_flush_stderr();

	_exit(status);
}
