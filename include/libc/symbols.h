#ifndef SYMBOLS_H_
#define SYMBOLS_H_

#define __alias(NAME)	__attribute__((alias(#NAME)))
#define __weak(NAME)	__attribute__((weak, alias(#NAME)))

#define weak_alias(NAME, ALIAS) \
extern __typeof__(NAME) ALIAS __weak(NAME)

#define strong_alias(NAME, ALIAS) \
extern __typeof__(NAME) ALIAS __alias(NAME)

#define EXPORT__(TYPE, NAME)	\
extern __typeof__(NAME) __ ## NAME; \
extern __typeof__(NAME) NAME __attribute__((weak, alias("__" #NAME))); \
TYPE __ ## NAME

#endif
