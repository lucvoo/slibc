#include <dirent.h>
#include <string.h>

int alphasort(const struct dirent **a, const struct dirent **b)
{
	return strcoll(a[0]->d_name, b[0]->d_name);
}
