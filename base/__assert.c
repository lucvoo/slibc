#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "libc/stdlib.h"		// for __ltostr()
#include "libc/cdefs.h"
#include "libc/link_warning.h"

#undef	NDEBUG
#include <assert.h>

#define bufcpy(dest, src, len)	\
	memcpy(dest, src, len);	ptr += len
#define bufapp(dest, str) \
	bufcpy(dest, str, sizeof(str)-1);

void __libc_assert(const char *expr, const char *file, unsigned int line, const char *func)
{
	size_t e_len, f_len, l_len, fulen;
	char *buf;

	e_len = strlen(expr);
	f_len = strlen(file);
	fulen = strlen(func);
	buf = __builtin_alloca(f_len + 10 + fulen + e_len + 40);

	if (__likely(! !buf)) {
		char *ptr = buf;

		bufcpy(ptr, file, f_len);
		bufapp(ptr, ":");
		l_len = __ltostr(ptr, 10, line);
		ptr += l_len;
		bufapp(ptr, ": ");
		bufcpy(ptr, func, fulen);
		bufapp(ptr, "(): Assertion `");
		bufcpy(ptr, expr, e_len);
		bufapp(ptr, "' failed.\n");

		write(2, buf, ptr - buf);
	}

	abort();
}
