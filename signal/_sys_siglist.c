#include <signal.h>

const char *_sys_siglist[_NSIG] = {
#define DEF(Name, Desc)	[SIG##Name] = Desc,
#include "./_sys_siglist.def"
#undef	DEF
};
