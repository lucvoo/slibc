#ifndef LINK_WARNING_H_
#define LINK_WARNING_H_

#define link_warning(symbol, msg) \
__asm__(".section .gnu.warning." #symbol "\n" \
	"\t.string \"warning: " msg "\"\n" \
	"\t.previous")

#define warn_legacy(symbol, newer) \
	link_warning(symbol, #symbol "() is a legacy function, use " newer " instead.");
#define warn_obsolete(symbol, newer) \
	link_warning(symbol, #symbol "() is obsoleted, use " newer " instead.");
#define warn_unbounded(symbol, newer) \
	link_warning(symbol, #symbol "'s buffer are unbounded, use " newer " instead.");

#endif
