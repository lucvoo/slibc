#include "_serv.h"
#include <string.h>			// for strcmp()

int __libc_getservport(struct servent *ent, char *buf, size_t size, int port, const char *proto)
{
	parse_state_t state;
	int notfound = 1;

	if (__libc_parse_start(_PATH_SERVICES, &state))
		return notfound;

	if (!proto) {
		while (__libc_getservent(ent, buf, size, &state) == 0) {
			if (ent->s_port == port) {
				notfound = 0;
				break;
			}
		}
	} else {
		while (__libc_getservent(ent, buf, size, &state) == 0) {
			if (ent->s_port == port && strcmp(ent->s_proto, proto) == 0) {
				notfound = 0;
				break;
			}
		}
	}

	__libc_parse_finish(&state);
	return notfound;
}
