#ifndef _VGACORE_H_
#define _VGACORE_H_

#include <stdint.h>

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

namespace Vga
{
    extern volatile uint8_t VideoMemoryPixels[];
    extern volatile uint8_t VideoMemoryAttributes[];

	void InitVga(VideoSettings* videoSettings);

    volatile uint8_t* GetBitmapAddress(uint8_t vline);
    volatile uint8_t* GetBitmapAddress(uint8_t vline, uint8_t character);

    void delay_frame();
	void clear_screen(uint8_t attribute);
}

#endif
