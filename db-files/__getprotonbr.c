#include "_proto.h"

int __libc_getprotonbr(struct protoent *ent, char *buf, size_t size, int proto)
{
	parse_state_t state;
	int notfound = 1;

	if (__libc_parse_start(_PATH_PROTOCOLS, &state))
		return notfound;

	while (__libc_getprotoent(ent, buf, size, &state) == 0) {
		if (ent->p_proto == proto) {
			notfound = 0;
			break;
		}
	}

	__libc_parse_finish(&state);
	return notfound;
}
