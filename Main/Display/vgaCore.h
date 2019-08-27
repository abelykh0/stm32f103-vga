#ifndef _VGACORE_H_
#define _VGACORE_H_

#include <stdint.h>

#include "attribute.h"
#include "settings.h"
#include "VideoSettings.h"

/*
	Pinout
	======

	PB6 - VSync
	PB0 - HSync

	PA0, PA1 - Red
	PA2, PA3 - Green
	PA4, PA5 - Blue

	Resistors
	=========
	680 Ohm on PA0, PA2, PA4 (0.33 V)
	470 Ohm on PA1, PA2, PA3
	====
	Parallel: 278 Ohm (0.7 V)

*/


// Horizontal resolution
#define	HSIZE_PIXELS  (HSIZE_CHARS * 8)

// Vertical resolution
#define	VSIZE_PIXELS  (VSIZE_CHARS * 8)

#define	BITMAP_SIZE     (HSIZE_CHARS * VSIZE_PIXELS)
#define	ATTRIBUTES_SIZE (HSIZE_CHARS * VSIZE_CHARS)

namespace Vga
{
    extern uint8_t* VideoMemoryPixels;
    extern uint8_t* VideoMemoryAttributes;
    extern Attribute* AttributeBase;
	extern Attribute DefaultAttributeDefinition;

	void InitVga(VideoSettings* videoSettings);

    uint8_t* GetBitmapAddress(uint8_t vline);
    uint8_t* GetBitmapAddress(uint8_t vline, uint8_t character);

    void InitAttribute(Attribute attribute, uint8_t backColor, uint8_t foreColor);
    void delay_frame();
	void clear_screen(uint8_t attribute);
}

#endif
