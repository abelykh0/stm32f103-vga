#ifndef _VIDEOSETTINGS_H
#define _VIDEOSETTINGS_H

#include <stdint.h>
#include "attribute.h"
#include "timing.h"

namespace Vga
{

class VideoSettings
{
  public:
	const Vga::Timing* Timing;

	// text resolution
	uint8_t TextColumns;
	uint8_t TextRows;

	// video memory
	uint8_t* ScreenPixels;
	uint8_t* ScreenAttributes;
	Attribute* AttributeBase;
};

}

#endif
