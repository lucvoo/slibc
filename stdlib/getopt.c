#include <getopt.h>

#include <unistd.h>			// For write(2)
#include <string.h>			// For strchr(3)

char *optarg;
int optind = 1, opterr, optopt;

#define UNKNOWN		0
#define MISSING		1

static void getopt_error(int err)
{
	static char msg_unknown[] = "Unknown option `-x'.\n";
	static char msg_missing[] = "Missing argument for `-x'.\n";
	char *msg;
	int siz;

	switch (err) {
	case UNKNOWN:
		msg = msg_unknown;
		siz = sizeof(msg_unknown);
		break;
	case MISSING:
		msg = msg_missing;
		siz = sizeof(msg_missing);
		break;
	default:			// never reached;
		return;
	}

	msg[siz - 5] = optopt;
	write(2, msg, siz - 1);
}

int getopt(int argc, char *const argv[], const char *optstring)
{
	static int ind;			// internal state: optind
	static int off;			// internal state: "multi-option"
	char *arg;			// current argument
	const char *ptr;		// position in optstring

start:
	if (optind > argc)
		return -1;
	arg = argv[optind];

	// if optind have changed: reset multi-option and check
	if (ind != optind) {
		ind = optind;
		off = 1;

		// return -1 if:        arg is null,
		//                      arg do not start with '-',
		//                      arg is "-"
		if (!arg || arg[0] != '-' || arg[1] == '\0')
			return -1;

		// return -1 and increment optind if: arg is "--"
		if (arg[1] == '-' && arg[2] == '\0') {
			optind++;
			return -1;
		}
	}

	optopt = arg[off];
	off++;
	if (!optopt)			// last (multi-) option
	{
		optind++;		// try next argument
		goto start;
	}

	ptr = strchr(optstring, optopt);
	if (!ptr)			// unknown option
	{
		if (opterr)
			getopt_error(UNKNOWN);
		return '?';
	}
	if (ptr[1] == ':')		// expect an argument
	{
		if (arg[off])		// case -oarg => -o arg
		{
			optarg = arg + off;
			optind++;
		} else			// case -mno
		{
			optarg = argv[optind + 1];
			optind += 2;
			if (optind > argc)	// missing option argument
			{
				if (optstring[0] == ':')
					return ':';
				else {
					if (opterr)
						getopt_error(MISSING);
					return '?';
				}
			}
		}
	}

	return optopt;
}
