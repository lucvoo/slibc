#ifndef _ARCH_SOCKET_H
#define _ARCH_SOCKET_H

// For setsockopt(2)
#define SOL_SOCKET	1

// For getsockopt() & setsockopt()
#define SO_DEBUG	1
#define SO_REUSEADDR	2
#define SO_TYPE		3
#define SO_ERROR	4
#define SO_DONTROUTE	5
#define SO_BROADCAST	6
#define SO_SNDBUF	7
#define SO_RCVBUF	8
#define SO_KEEPALIVE	9
#define SO_OOBINLINE	10
#define SO_NO_CHECK	11
#define SO_PRIORITY	12
#define SO_LINGER	13
#define SO_BSDCOMPAT	14
// To add :#define SO_REUSEPORT 15
#define SO_RCVLOWAT	16
#define SO_SNDLOWAT	17
#define SO_RCVTIMEO	18
#define SO_SNDTIMEO	19
#define SO_PASSCRED	20
#define SO_PEERCRED	21

// Security levels - as per NRL IPv6 - don't actually do anything
#define SO_SECURITY_AUTHENTICATION		22
#define SO_SECURITY_ENCRYPTION_TRANSPORT	23
#define SO_SECURITY_ENCRYPTION_NETWORK		24

#define SO_BINDTODEVICE	25

// Socket filtering
#define SO_ATTACH_FILTER	26
#define SO_DETACH_FILTER	27

#define SO_PEERNAME		28
#define SO_TIMESTAMP		29
#define SCM_TIMESTAMP		SO_TIMESTAMP
#define SO_ACCEPTCONN		30
#define SO_PEERSEC		31

// Socket types
#define SOCK_STREAM	1		// stream (connection) socket
#define SOCK_DGRAM	2		// datagram (conn.less) socket
#define SOCK_RAW	3		// raw socket
#define SOCK_RDM	4		// reliably-delivered message
#define SOCK_SEQPACKET	5		// sequential packet socket
#define SOCK_PACKET	10		// For writing rarp and other similar things

#define SOCK_MAX	(SOCK_PACKET+1)

#endif
