#ifndef _NETDB_H
#define _NETDB_H

#include <netinet/in.h>
#include <sys/socket.h>
#include <inttypes.h>

#define IPPORT_RESERVED		1024

#define HOST_NOT_FOUND		1
#define TRY_AGAIN		2
#define NO_RECOVERY		3
#define NO_ADDRESS		4	// non SuS
#define NO_DATA			5

struct hostent {
	char		*h_name;
	char		**h_aliases;
	int		h_addrtype;
	int		h_length;
	char		**h_addr_list;
// FIXME: #define h_addr        h_addr_list[0];
};

void endhostent(void);
struct hostent *gethostbyaddr(const void *addr, socklen_t, int type);
struct hostent *gethostbyname(const char *name);
struct hostent *gethostent(void);
void sethostent(int stayopen);

struct netent {
	char		*n_name;
	char		**n_aliases;
	int		n_addrtype;
	uint32_t	n_net;
};

void endnetent(void);
struct netent *getnetbyaddr(uint32_t net, int type);
struct netent *getnetbyname(const char *name);
struct netent *getnetent(void);
void setnetent(int stayopen);

struct protoent {
	char		*p_name;
	char		**p_aliases;
	int		p_proto;
};

void endprotoent(void);
struct protoent *getprotobyname(const char *name);
struct protoent *getprotobynumber(int proto);
struct protoent *getprotoent(void);
void setprotoent(int stayopen);

struct servent {
	char		*s_name;
	char		**s_aliases;
	int		s_port;
	char		*s_proto;
};

void endservent(void);
struct servent *getservbyname(const char *name, const char *proto);
struct servent *getservbyport(int port, const char *proto);
struct servent *getservent(void);
void setservent(int stayopen);

struct addrinfo {
	int		ai_flags;
	int		ai_family;
	int		ai_socktype;
	int		ai_protocol;
	socklen_t	ai_addrlen;
	struct sockaddr	*ai_addr;
	char		*ai_canonname;
	struct addrinfo	*ai_next;
};

// FIXME: thread safe ???
extern int h_errno;

void freeaddrinfo(struct addrinfo *);
const char *gai_strerror(int);
int getaddrinfo(const char *restrict, const char *restrict,
		const struct addrinfo *restrict, struct addrinfo **restrict);
int getnameinfo(const struct sockaddr *restrict, socklen_t,
		char *restrict, socklen_t, char *restrict, socklen_t, int);

// values for struct addrinfo's ai_flags
#define AI_PASSIVE	0x01
#define AI_CANONNAME	0x02
#define AI_NUMERICHOST	0x04
#define AI_NUMERICSERV	?		// FIXME: missing
#define AI_V4MAPPED	?		// FIXME: missing
#define AI_ALL		?		// FIXME: missing
#define AI_ADDRCONFIG	?		// FIXME: missing

// values for getnameinfo()'s flags argument
#define NI_NOFQDN	0x01
#define NI_NUMERICHOST	0x02
#define NI_NAMEREQD	0x04
#define NI_NUMERICSERV	0x08
#define NI_DGRAM	0x10

// error values for getaddrinfo() & getnameinfo()
#define EAI_AGAIN	-1
#define EAI_BADFLAGS	-2
#define EAI_FAIL	-3
#define EAI_FAMILY	-4
#define EAI_MEMORY	-5
#define EAI_NODATA	-6
#define EAI_NONAME	-7
#define EAI_SERVICE	-8
#define EAI_SOCKTYPE	-9
#define EAI_SYSTEM	-10
#define EAI_OVERFLOW	-11

#define EAI_ADDRFAMILY	-12		// FIXME: glibcism

// FIXME: should we define h_errno ???

// non SuS
//#define _PATH_HEQUIV          "/etc/hosts.equiv"
#define _PATH_HOSTS		"/etc/hosts"
#define _PATH_NETWORKS		"/etc/networks"
#define _PATH_PROTOCOLS		"/etc/protocols"
#define _PATH_SERVICES		"/etc/services"

#endif
