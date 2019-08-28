#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include "startup.h"
#include "Display/vga.h"
#include "Display/timing.h"
#include "Keyboard/ps2Keyboard.h"

using namespace Vga;

static uint8_t _screenPixels[HSIZE_CHARS * VSIZE_PIXELS];
static uint8_t _screenAttributes[HSIZE_CHARS * VSIZE_CHARS];
static Attribute _defaultAttributeDefinition;

static VideoSettings Video {
	&TIMING,
	HSIZE_CHARS, VSIZE_CHARS,
	_screenPixels, _screenAttributes, _defaultAttributeDefinition.a
};

extern "C" void initialize()
{
}

extern "C" void setup()
{
	InitAttribute(&_defaultAttributeDefinition, BACK_COLOR, FORE_COLOR);
	InitVga(&Video);

	// Initialize PS2 Keyboard
	//Ps2_Initialize();

    // Display frame
	printAt(0, 0, "\xC9", 0); // ╔
	printAt(HSIZE_CHARS - 1, 0, "\xBB", 0); // ╗
	printAt(0, VSIZE_CHARS - 1, "\xC8", 0); // ╚
	printAt(HSIZE_CHARS - 1, VSIZE_CHARS - 1, "\xBC", 0); // ╝
    for (int i = 1; i < HSIZE_CHARS - 1; i++)
    {
    	printAt(i, 0, "\x0CD", 0); // ═
    	printAt(i, VSIZE_CHARS - 1, "\x0CD", 0); // ═
    }
    for (int i = 1; i < VSIZE_CHARS - 1; i++)
    {
    	printAt(0, i, "\x0BA", 0); // ║
    	printAt(HSIZE_CHARS - 1, i, "\x0BA", 0); // ║
    }
}

extern "C" void loop()
{
	int32_t scanCode = Ps2_GetScancode();
	if (scanCode > 0)
	{
		//char buf[30];
		//snprintf(buf, 30, "%04lx", (uint32_t)scanCode);
		//Print(buf);

//		if ((scanCode & 0xFF00) != 0xF000)
//		{
//			// key down
//			switch (scanCode)
//			{
//			case KEY_LEFTARROW:
//				if (Vga::cursor_x > 0)
//				{
//					Vga::SetAttribute(Vga::cursor_x - 1, Vga::cursor_y, (int32_t)Vga::StandardAttribute);
//					Vga::SetCursorPosition(Vga::cursor_x - 1, Vga::cursor_y);
//				}
//				break;
//			case KEY_BACKSPACE:
//				if (Vga::cursor_x > 0)
//				{
//					Vga::SetCursorPosition(Vga::cursor_x - 1, Vga::cursor_y);
//					Vga::PrintChar(Vga::cursor_x, Vga::cursor_y, ' ', (int32_t)Vga::StandardAttribute);
//				}
//				break;
//			case KEY_RIGHTARROW:
//				if (Vga::cursor_x < HSIZE_CHARS - 1)
//				{
//					Vga::SetAttribute(Vga::cursor_x + 1, Vga::cursor_y, (int32_t)Vga::StandardAttribute);
//					Vga::SetCursorPosition(Vga::cursor_x + 1, Vga::cursor_y);
//				}
//				break;
//			case KEY_UPARROW:
//				if (Vga::cursor_y > 0)
//				{
//					Vga::SetAttribute(Vga::cursor_x, Vga::cursor_y - 1, (int32_t)Vga::StandardAttribute);
//					Vga::SetCursorPosition(Vga::cursor_x, Vga::cursor_y - 1);
//				}
//				break;
//			case KEY_DOWNARROW:
//				if (Vga::cursor_y < VSIZE_CHARS - 1)
//				{
//					Vga::SetAttribute(Vga::cursor_x, Vga::cursor_y + 1, (int32_t)Vga::StandardAttribute);
//					Vga::SetCursorPosition(Vga::cursor_x, Vga::cursor_y + 1);
//				}
//				break;
//			default:
//				char buf[2];
//				buf[0] = Ps2_ConvertScancode(scanCode);
//				if (buf[0] != '\0')
//				{
//					buf[1] = '\0';
//					Vga::Print(buf, (int32_t)Vga::StandardAttribute);
//				}
//			}
//		}
	}

	//HAL_Delay(10);
}
