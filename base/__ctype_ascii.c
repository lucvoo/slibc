#include <ctype.h>

const unsigned int __ctype_ascii[257] = {
0,							// -1 (EOF)
_ISascii|_IScntrl,					// NUL
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//
_ISascii|_IScntrl,					//
_ISascii|_IScntrl,					// BS
_ISascii|_IScntrl|_ISspace|_ISblank,			// HT
_ISascii|_IScntrl|_ISspace,				//   .
_ISascii|_IScntrl|_ISspace,				//   .
_ISascii|_IScntrl|_ISspace,				//   .
_ISascii|_IScntrl|_ISspace,				// CR
_ISascii|_IScntrl,					// SO
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					//   .
_ISascii|_IScntrl,					// US
_ISascii|_ISprint|_ISspace|_ISblank,			// ' '
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '!'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '"'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '#'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '$'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '%'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '&'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '\''
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '('
_ISascii|_ISprint|_ISpunct|_ISgraph,			// ')'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '*'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '+'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// ','
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '-'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '.'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '/'
_ISascii|_ISprint|_ISdigit|_ISxdigit|_ISgraph,		// '0'
_ISascii|_ISprint|_ISdigit|_ISxdigit|_ISgraph,		// '1'
_ISascii|_ISprint|_ISdigit|_ISxdigit|_ISgraph,		// '2'
_ISascii|_ISprint|_ISdigit|_ISxdigit|_ISgraph,		// '2'
_ISascii|_ISprint|_ISdigit|_ISxdigit|_ISgraph,		// '4'
_ISascii|_ISprint|_ISdigit|_ISxdigit|_ISgraph,		// '5'
_ISascii|_ISprint|_ISdigit|_ISxdigit|_ISgraph,		// '6'
_ISascii|_ISprint|_ISdigit|_ISxdigit|_ISgraph,		// '7'
_ISascii|_ISprint|_ISdigit|_ISxdigit|_ISgraph,		// '8'
_ISascii|_ISprint|_ISdigit|_ISxdigit|_ISgraph,		// '9'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// ':'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// ';'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '<'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '='
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '>'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '?'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '@'
_ISascii|_ISprint|_ISupper|_ISxdigit|_ISalpha|_ISgraph,	// 'A'
_ISascii|_ISprint|_ISupper|_ISxdigit|_ISalpha|_ISgraph,	// 'B'
_ISascii|_ISprint|_ISupper|_ISxdigit|_ISalpha|_ISgraph,	// 'C'
_ISascii|_ISprint|_ISupper|_ISxdigit|_ISalpha|_ISgraph,	// 'D'
_ISascii|_ISprint|_ISupper|_ISxdigit|_ISalpha|_ISgraph,	// 'E'
_ISascii|_ISprint|_ISupper|_ISxdigit|_ISalpha|_ISgraph,	// 'F'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'G'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'H'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'I'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'J'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'K'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'L'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'M'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'N'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'O'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'P'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'Q'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'R'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'S'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'T'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'U'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'V'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'W'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'X'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'Y'
_ISascii|_ISprint|_ISupper|_ISalpha|_ISgraph,		// 'Z'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '['
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '\\'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// ']'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '^'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '_'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '`'
_ISascii|_ISprint|_ISlower|_ISxdigit|_ISalpha|_ISgraph,	// 'a'
_ISascii|_ISprint|_ISlower|_ISxdigit|_ISalpha|_ISgraph,	// 'b'
_ISascii|_ISprint|_ISlower|_ISxdigit|_ISalpha|_ISgraph,	// 'c'
_ISascii|_ISprint|_ISlower|_ISxdigit|_ISalpha|_ISgraph,	// 'd'
_ISascii|_ISprint|_ISlower|_ISxdigit|_ISalpha|_ISgraph,	// 'e'
_ISascii|_ISprint|_ISlower|_ISxdigit|_ISalpha|_ISgraph,	// 'f'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'g'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'h'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'i'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'j'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'k'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'l'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'm'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'n'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'o'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'p'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'q'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'r'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 's'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 't'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'u'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'v'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'w'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'x'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'y'
_ISascii|_ISprint|_ISlower|_ISalpha|_ISgraph,		// 'z'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '{'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '|'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '}'
_ISascii|_ISprint|_ISpunct|_ISgraph,			// '~'
_ISascii|_IScntrl,					// '^?'
};

#include "libc/symbols.h"
weak_alias(__ctype_ascii, __ctype);
