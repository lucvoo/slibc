#include <net/if.h>
#include <sys/socket.h>			// for socket()
#include <sys/ioctl.h>			// for ioctl()
#include <unistd.h>			// for close()
#include <string.h>			// for strlen() & strcpy()
#include "linux/sockios.h"		// for SIOCGIFNAME
#include "libc/cdefs.h"

// FIXME: true definition in linux/if.h
struct __ifreq {
	char ifr_name[IF_NAMESIZE];
	int ifr_index;
};

unsigned int if_nametoindex(const char *name)
{
	struct __ifreq ifr;
	// FIXME: should save and restore errno ???
	int fd;
	int rc;

	if (__unlikely(strlen(name) >= IF_NAMESIZE))
		return 0;

	// Open an random socket just have a fd for ioctl.
	fd = socket(AF_INET, SOCK_DGRAM, 0);
	// FIXME: try first with AF_INET6
	// FIXME: best choice of family/protocol ???
	if (__unlikely(fd == -1))
		return 0;

	strcpy(ifr.ifr_name, name);
	rc = ioctl(fd, SIOCGIFINDEX, &ifr);
	close(fd);

	if (__likely(rc == 0))
		return ifr.ifr_index;
	else
		return 0;
}
