#include <sys/mman.h>
#include "db-files.h"
#include <values/NULL.h>

void __libc_parse_finish(parse_state_t * s)
{
	munmap((char *)s->buf, s->end - s->buf);
	s->buf = NULL;
}
