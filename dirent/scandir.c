#include <dirent.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include "libc/cdefs.h"

typedef int (*sel_fun) (const struct dirent *);
typedef int (*cmp_fun) (const struct dirent **, const struct dirent **);

int scandir(const char *dir, struct dirent ***nlist, sel_fun sel, cmp_fun cmp)
{
	struct dirent *de;
	struct dirent **list;
	int ncur, nmax;
	DIR *d;

	d = opendir(dir);
	if (!d)
		return -1;

	list = NULL;
	ncur = 0;
	nmax = 0;
	while ((de = readdir(d))) {
		void *tmp;

		if (sel && !sel(de))
			continue;

		// must add this one
		if (__unlikely(ncur == nmax)) {
			nmax = nmax * 2 + 1;
			tmp = realloc(list, nmax * sizeof(struct dirent *));
			if (__unlikely(!tmp))
				goto error;
			list = tmp;
		}

		tmp = malloc(de->d_reclen);
		if (__unlikely(!tmp))
			goto error;
		memcpy(tmp, de, de->d_reclen);
		list[ncur++] = tmp;
	}

	// sort if necessary
	if (cmp)
		qsort(list, ncur, sizeof(struct dirent *), (int (*)(const void *, const void *))cmp);

	// That's all
	*nlist = list;
	closedir(d);
	// FIXME: errno handling
	return ncur;

error:
	// FIXME: errno handling
	for (; ncur--;)
		free(list[ncur]);
	free(list);
	closedir(d);
	return -1;
}
