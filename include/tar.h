#ifndef _TAR_H
#define _TAR_H

// General definitions:
#define TMAGIC		"ustar"
#define TMAGLEN		6
#define TVERSION	"00"
#define TVERSLEN	2

// The typeflag field definition:
#define REGTYPE		'0'		// Regular file (preferred code).
#define AREGTYPE	'\0'		// Regular file (alternate code).
#define LNKTYPE		'1'		// Hard link.
#define SYMTYPE		'2'		// Symbolic link.
#define CHRTYPE		'3'		// Character special.
#define BLKTYPE		'4'		// Block special.
#define DIRTYPE		'5'		// Directory.
#define FIFOTYPE	'6'		// FIFO specila (Named pipe).
#define CONTTYPE	'7'		// Reserved (Contiguous file).

// The mode field bit definition:
#define TSUID		04000
#define TSGID		02000
#define TSVTX		01000
#define TUREAD		00400
#define TUWRITE		00200
#define TUEXEC		00100
#define TGREAD		00040
#define TGWRITE		00020
#define TGEXEC		00010
#define TOREAD		00004
#define TOWRITE		00002
#define TOEXEC		00001

#endif
