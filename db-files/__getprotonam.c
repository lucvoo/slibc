#include "_proto.h"
#include <string.h>			// for strcmp()

int __libc_getprotonam(struct protoent *ent, char *buf, size_t size, const char *name)
{
	parse_state_t state;
	int notfound = 1;

	if (__libc_parse_start(_PATH_PROTOCOLS, &state))
		return notfound;

	while (__libc_getprotoent(ent, buf, size, &state) == 0) {
		if (strcmp(ent->p_name, name) == 0) {
			notfound = 0;
			break;
		}
	}

	__libc_parse_finish(&state);
	return notfound;
}
