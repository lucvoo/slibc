#include "_net.h"
#include <string.h>			// for strcmp()

int __libc_getnetnam(struct netent *ent, char *buf, size_t size, const char *name)
{
	parse_state_t state;
	int notfound = 1;

	if (__libc_parse_start(_PATH_NETWORKS, &state))
		return notfound;

	while (__libc_getnetent(ent, buf, size, &state) == 0) {
		if (strcmp(ent->n_name, name) == 0) {
			notfound = 0;
			break;
		}
	}

	__libc_parse_finish(&state);
	return notfound;
}
