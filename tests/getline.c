#include <stdio.h>
#include <string.h>

int main(void)
{
	char *line = 0;
	size_t size;
	int err = 0;
	int n;

	while ((n = getline(&line, &size, stdin)) != -1) {
		size_t len;

		len = strlen(line);
		if (len != (size_t) n) {
			fprintf(stderr, "lenght disagree: %4u != %4u\n", n, len);
			err++;
		}
		if (len == 0) {
			fprintf(stderr, "lenght disagree: %4u != %4u\n", n, len);
			err++;
		}
		if (size < (len + 2)) {
			fprintf(stderr, "line allocation bug: %u < %u+2\n", size, len);
			err++;
		}
		if (line[len - 1] != '\n') {
			fprintf(stderr, "line not terminated by a newline but by '0x%02x'\n",
				line[len - 1]);
			err++;
		} else
			line[len - 1] = '\0';

		printf("=>\"%s\"\n", line);
	}

	return 0;
}
