#ifndef _NETINET_TCP_H
#define _NETINET_TCP_H

// values for a socket option at the IPPROTO_TCP level
#define TCP_NODELAY		1	// Turn off Nagle's algorithm.
#define TCP_MAXSEG		2	// Limit MSS
#define TCP_CORK		3	// Never send partial segments
#define TCP_KEEPIDLE		4	// Start keeplives after this period
#define TCP_KEEPINTVL		5	// Interval between keepalives
#define TCP_KEEPCNT		6	// Number of keepalives before death
#define TCP_SYNCNT		7	// Number of SYN retransmits
#define TCP_LINGER2		8	// Life time of orphaned FIN-WAIT-2
#define TCP_DEFER_ACCEPT	9	// Wake up listener only when data
#define TCP_WINDOW_CLAMP	10	// Bound advertised window
#define TCP_INFO		11	// Information about this connection.
#define TCP_QUICKACK		12	// Block/reenable quick acks

#endif
