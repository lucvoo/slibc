#ifndef _SYS_UN_H
#define _SYS_UN_H

#include <types/sa_family_t.h>

struct sockaddr_un {
	sa_family_t	sun_family;
	char		sun_path[108];
};

#endif
