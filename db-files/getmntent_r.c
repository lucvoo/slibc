#include <sys/mntent.h>
#include <ctype.h>
#include <string.h>
#include "libc/stdlib.h"		// for __atoul;

static inline char *next_field(char *ptr)
{
	while (isspace(*ptr))
		ptr++;

	return ptr;
}

static inline char *end_field(char *ptr)
{
	while (!isspace(*ptr))
		ptr++;
	*ptr = '\0';

	return next_field(ptr + 1);
}

struct mntent *getmntent_r(FILE * S, struct mntent *mp, char *buf, size_t size)
{
	char *line;
	char *ptr;

start:
	line = buf;
	// read one entry
	if (fgets(line, size, S) != line)
		return NULL;

	// search after the trailing '\n'
	ptr = strchr(line, '\n');
	if (!ptr)			// buffer was too small
		return NULL;

	ptr[0] = '\0';			// chop the line
	// FIXME: usefull ???

	// strip leading whitespace
	ptr = next_field(line);

	// skip comment & empty line
	if (ptr[0] == '\0' || ptr[0] == '#')
		goto start;

// FIXME: this is UGLY !!!
	// copy the fields
	mp->mnt_fsname = ptr;
	ptr = end_field(ptr);

	ptr = next_field(ptr);
	mp->mnt_dir = ptr;
	ptr = end_field(ptr);

	ptr = next_field(ptr);
	mp->mnt_type = ptr;
	ptr = end_field(ptr);

	ptr = next_field(ptr);
	mp->mnt_opts = ptr;
	ptr = end_field(ptr);

	ptr = next_field(ptr);
	mp->mnt_freq = __atoul(ptr);
	ptr = end_field(ptr);

	ptr = next_field(ptr);
	mp->mnt_passno = __atoul(ptr);

	return mp;
}
