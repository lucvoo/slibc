#ifndef _LOCALE_H
#define _LOCALE_H

#define LC_COLLATE		0x0001
#define LC_CTYPE		0x0002
#define LC_MESSAGES		0x0004
#define LC_MONETARY		0x0008
#define LC_NUMERIC		0x0010
#define LC_TIME			0x0020
#define LC_ADDRESS		0x0040
#define LC_IDENTIFICATION	0x0080
#define LC_MEASUREMENT		0x0100
#define LC_NAME			0x0200
#define LC_PAPER		0x0400
#define LC_TELEPHONE		0x0800

#define LC_ALL			0x0FFF

char *setlocale(int category, const char *locale);

#endif
