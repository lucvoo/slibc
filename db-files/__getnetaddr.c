#include "_net.h"

int __libc_getnetaddr(struct netent *ent, char *buf, size_t size, uint32_t addr, int type)
{
	parse_state_t state;
	int notfound = 1;

	if (__libc_parse_start(_PATH_NETWORKS, &state))
		return notfound;

	while (__libc_getnetent(ent, buf, size, &state) == 0) {
		if ((ent->n_net == addr) && (ent->n_addrtype = type)) {
			notfound = 0;
			break;
		}
	}

	__libc_parse_finish(&state);
	return notfound;
}
