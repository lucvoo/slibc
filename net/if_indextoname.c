#include <net/if.h>
#include <sys/socket.h>			// for socket()
#include <sys/ioctl.h>			// for ioctl()
#include <unistd.h>			// for close()
#include "linux/sockios.h"		// for SIOCGIFNAME
#include "libc/cdefs.h"

// FIXME: true definition in linux/if.h
struct __ifreq {
	char ifr_name[IF_NAMESIZE];
	int ifr_index;
};

char *if_indextoname(unsigned int index, char *name)
{
	struct __ifreq ifr;
	// FIXME: should save and restore errno ???
	int fd;
	int rc;

	// Open an random socket just have a fd for ioctl.
	fd = socket(AF_INET, SOCK_DGRAM, 0);
	// FIXME: try first with AF_INET6
	// FIXME: best choice of family/protocol ???
	if (__unlikely(fd == -1))
		return NULL;

	ifr.ifr_index = index;
	rc = ioctl(fd, SIOCGIFNAME, &ifr);
	close(fd);
	if (__likely(rc == 0)) {
		__builtin_memcpy(name, ifr.ifr_name, sizeof(ifr.ifr_name));
		return name;
	} else
		return NULL;
}
