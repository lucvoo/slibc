#ifndef _AR_H
#define _AR_H

#define ARMAG	"!<arch>\n"		// String that begins an archive file.
#define SARMAG	8			// Size of that string.
#define ARFMAG	"`\n"			// String in ar_fmag.

struct ar_hdr {
	char		ar_name[16];	// member/file name
	char		ar_date[12];	// seconds since Epoch, in ASCII decimal
	char		ar_uid[6];	// in ASCII decimal
	char		ar_gid[6];	// in ASCII decimal.
	char		ar_mode[8];	// in ASCII octal.
	char		ar_size[10];	// in ASCII decimal.
	char		ar_fmag[2];	// Always contains ARFMAG ?
};

#endif
