#ifndef VGA_ATTRIBUTE_H
#define VGA_ATTRIBUTE_H

#include "stdint.h"

namespace Vga
{

typedef struct _Attribute
{
	uint8_t a[64];
	uint8_t& operator[](int i) { return a[i]; }
} Attribute;

}

#endif // VGA_ATTRIBUTE_H
