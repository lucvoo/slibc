#ifndef _NETINET_IN_H
#define _NETINET_IN_H

// FIXME: split this header in IPV4 & IPV6 ???

#include <inttypes.h>
#include <sys/socket.h>

typedef uint16_t in_port_t;
typedef uint32_t in_addr_t;

struct in_addr {
	in_addr_t	s_addr;
};

struct sockaddr_in {
	sa_family_t	sin_family;		// FIXME
	in_port_t	sin_port;
	struct in_addr		sin_addr;
// FIXME: alignment & padding ???
};

struct in6_addr {
	uint8_t		s6_addr[16];
} __attribute__ ((aligned(8)));

struct sockaddr_in6 {
	sa_family_t	sin6_family;	// FIXME
	in_port_t	sin6_port;
	uint32_t	sin6_flowinfo;
	struct in6_addr	sin6_addr;
	uint32_t	sin6_scope_id;
};

extern const struct in6_addr in6addr_any;
extern const struct in6_addr in6addr_loopback;

#define IN6ADDR_ANY_INIT	{{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }}
#define IN6ADDR_LOOPBACK_INIT	{{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 }}

struct ipv6_mreq {
	struct in6_addr	ipv6mr_multiaddr;
	unsigned	ipv6mr_interface;
};

// values for level argument of getsockopt() & setsockopt()
#define IPPROTO_IP	0		// Dummy protocol for TCP
#define IPPROTO_ICMP	1		// Internet Control Message Protocol
#define IPPROTO_IGMP	2		// Internet Group Management Protocol
#define IPPROTO_IPIP	4		// IPIP tunnels
#define IPPROTO_TCP	6		// Transmission Control Protocol
#define IPPROTO_EGP	8		// Exterior Gateway Protocol
#define IPPROTO_PUP	12		// PUP protocol
#define IPPROTO_UDP	17		// User Datagram Protocol
#define IPPROTO_IDP	22		// XNS IDP protocol
#define IPPROTO_RSVP	46		// RSVP protocol
#define IPPROTO_GRE	47		// Cisco GRE tunnels (rfc 1701,1702)
#define IPPROTO_IPV6	41		// IPv6-in-IPv4 tunnelling
#define IPPROTO_PIM	103		// Protocol Independent Multicast
#define IPPROTO_ESP	50		// Encapsulation Security Payload
#define IPPROTO_AH	51		// Authentication Header protocol
#define IPPROTO_COMP	108		// Compression Header protocol
#define IPPROTO_RAW	255		// Raw IP packets

#define IPPROTO_MAX	256

// destination addresses for connect(), sendmsg() & sendto()
#define INADDR_ANY              ((uint32_t) 0x00000000)
#define INADDR_BROADCAST        ((uint32_t) 0xffffffff)
//#define INADDR_LOOPBACK         ((uint32_t) 0x7f000001)

#define INET_ADDRSTRLEN		16
#define INET6_ADDRSTRLEN	46

// Options for getsockopt() & setsockopt() at level IPPROTO_IPV6
#define IPV6_JOIN_GROUP		20
#define IPV6_LEAVE_GROUP	21
#define IPV6_MULTICAST_HOPS	18
#define IPV6_MULTICAST_IF	17
#define IPV6_MULTICAST_LOOP	19
#define IPV6_UNICAST_HOPS	16
#define IPV6_V6ONLY		?	// FIXME: missing

#if 0					// FIXME: non SuS
#define IPV6_ADDRFORM		1
#define IPV6_PKTINFO		2
#define IPV6_HOPOPTS		3
#define IPV6_DSTOPTS		4
#define IPV6_RTHDR		5
#define IPV6_PKTOPTIONS		6
#define IPV6_CHECKSUM		7
#define IPV6_HOPLIMIT		8
#define IPV6_NEXTHOP		9
#define IPV6_AUTHHDR		10
#define IPV6_ROUTER_ALERT	22
#define IPV6_MTU_DISCOVER	23
#define IPV6_MTU		24
#define IPV6_RECVERR		25
#endif

#define IN6_IS_ADDR_UNSPECIFIED(a)			\
	(   ((const uint32_t*) (a))[0] == 0		\
	 && ((const uint32_t*) (a))[1] == 0		\
	 && ((const uint32_t*) (a))[2] == 0		\
	 && ((const uint32_t*) (a))[3] == 0)

#define IN6_IS_ADDR_LOOPBACK(a)				\
	(   ((const uint32_t*) (a))[0] == 0		\
	 && ((const uint32_t*) (a))[1] == 0		\
	 && ((const uint32_t*) (a))[2] == 0		\
	 && ((const uint32_t*) (a))[3] == htonl(1))

#define IN6_IS_ADDR_MULTICAST(a)			\
	(   ((const uint8_t*) (a))[0] == 0xff)

#define IN6_IS_ADDR_LINKLOCAL(a)				\
	((((const uint32_t*) (a))[0] & htonl(0xffc00000))      \
	 	== htonl(0xfe800000))

#define IN6_IS_ADDR_SITELOCAL(a)				\
	((((const uint32_t*) (a))[0] & htonl(0xffc00000))	\
		== htonl(0xfec00000))

#define IN6_IS_ADDR_V4MAPPED(a)					\
	(   (((const uint32_t*) (a))[0] == 0)			\
	 && (((const uint32_t*) (a))[1] == 0)			\
	 && (((const uint32_t*) (a))[2] == htonl(0xffff)))

#define IN6_IS_ADDR_V4COMPAT(a)				\
	(   (((const uint32_t*) (a))[0] == 0)		\
	 && (((const uint32_t*) (a))[1] == 0)		\
	 && (((const uint32_t*) (a))[2] == 0)		\
	 && (ntohl(((const uint32_t*) (a))[3]) > 1))

#ifndef __STRICT_POSIX
#define IN6_ARE_ADDR_EQUAL(a,b) \
	(   (((const uint32_t*)(a))[0]==((const uint32_t*)(b))[0]) \
	 && (((const uint32_t*)(a))[1]==((const uint32_t*)(b))[1]) \
	 && (((const uint32_t*)(a))[2]==((const uint32_t*)(b))[2]) \
	 && (((const uint32_t*)(a))[3]==((const uint32_t*)(b))[3]))
#endif

#include <arpa/inet.h>

#endif
