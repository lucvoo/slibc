#ifndef _LINUX_MODULE_H
#define _LINUX_MODULE_H

struct module;				// FIXME: TODO

int init_module(const char *name, struct module *image);

#endif
