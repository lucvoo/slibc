#define _GNU_SOURCE			// for getline
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static
void perror_exit(const char *msg)
{
	perror(msg);
	exit(1);
}

char *joinpath(const char *dir, const char *file)
{
	char *out;

	if (file[0] == '/')		// absolute path
	{
		out = strdup(file);
		if (!out)
			perror_exit("strdup");
		return out;
	} else {
		size_t len1, len2;

		len1 = strlen(dir);
		len2 = strlen(file);
		out = malloc(len1 + 1 + len2 + 1);
		if (!out)
			perror_exit("strdup");
		memcpy(out, dir, len1);
		out[len1] = '/';
		memcpy(out + len1 + 1, file, len2 + 1);
	}

	return out;
}

void do_header(const char *dir, const char *file)
{
	FILE *in;
	char *path;
	char *line = 0;
	size_t len = 0;
	ssize_t read;

	path = joinpath(dir, file);
	in = fopen(path, "r");
	if (!in)
		perror_exit("fopen(input file)");

	while ((read = getline(&line, &len, in)) != -1) {
		if (memcmp(line, "@include ", 9) == 0) {	// process new include file
			const char *file;

			line[read - 1] = '\0';	// strip the leading newline
			file = line + 9;
			while (isspace(file[0]))
				file++;

			do_header(dir, file);
		} else
			fputs(line, stdout);
	}

	free(line);
	fclose(in);
	free(path);
}

static
void usage(const char *pname)
{
	fprintf(stderr, "usage: %s <include dir> infile outfile\n", pname);
	exit(1);
}

int main(int argc, const char *argv[])
{
	const char *dir;
	FILE *out;

	if (argc != 4)
		usage(argv[0]);

	dir = argv[1];
	out = freopen(argv[3], "w", stdout);
	if (!out)
		perror_exit("fopen(outfile) failed");

	do_header(dir, argv[2]);

	return 0;
}
