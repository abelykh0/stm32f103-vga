#ifndef _VGA_H_
#define _VGA_H_

#include "stdint.h"
#include "vgacore.h"

#define PIXEL_CLEAR 0
#define PIXEL_SET 1
#define PIXEL_INVERT 2

namespace Vga
{
	extern uint8_t cursor_x;
	extern uint8_t cursor_y;

	void draw_line(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t c);
    void draw_rect(uint8_t x0, uint8_t y0, uint8_t w, uint8_t h, char c, char fc);
	void set_pixel(uint8_t x, uint8_t y, char c);
	void bitmap(uint16_t x, uint16_t y, const uint8_t *bmp,
				uint16_t i, uint8_t width, uint8_t lines);
    void draw_char(const uint8_t* f, uint16_t x, uint16_t y, uint8_t c);
    void draw_text(const uint8_t* f, uint16_t x, uint16_t y, const char* str);

	void select_font(const uint8_t* f);
    void showCursor();
    void hideCursor();
    void setCursorPosition(uint8_t x, uint8_t y);
	void print(const char *str, uint8_t attribute);
	void print(uint8_t c, uint8_t attribute);
	void print_char(uint8_t x, uint8_t y, unsigned char c, uint8_t attribute);
	void printAt(uint8_t x, uint8_t y, const char* str, uint8_t attribute);
}

#endif
