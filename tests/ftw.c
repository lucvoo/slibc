#include <ftw.h>
#include <stdio.h>

static
int fun(const char *name, const struct stat *sbuf, int flag)
{
	const char *suffix;

	(void)sbuf;

	switch (flag) {
	case FTW_D:
	case FTW_DNR:
		suffix = "/";
		break;
	case FTW_SL:
		suffix = "->";
		break;
	case FTW_F:
		suffix = "";
		break;
	default:
	case FTW_NS:
		suffix = "???";
		break;
	}

	printf("%s%s\n", name, suffix);

	return 0;
}

int main(int argc, const char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "usage: ftw <pathname>\n");
		return 1;
	}

	return ftw(argv[1], fun, 256);
}
