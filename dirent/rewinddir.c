#include "libc/dirent.h"

void rewinddir(DIR * d)
{
	seekdir(d, 0);
}
