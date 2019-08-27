#include <string.h>
#include <stdint.h>
#include <stdio.h>

#include "startup.h"
#include "Display/vgaCore.h"
#include "Display/timing.h"
#include "Keyboard/ps2Keyboard.h"

static uint8_t _screenPixels[HSIZE_CHARS * VSIZE_CHARS + 1];
static uint8_t _screenAttributes[HSIZE_CHARS * VSIZE_CHARS + 1];

using namespace Vga;

static VideoSettings Video {
	&TIMING,
	HSIZE_CHARS, VSIZE_CHARS,
	_screenPixels, _screenAttributes
};
extern "C" void initialize()
{
}

extern "C" void setup()
{
	InitVga(&Video);

	// Initialize PS2 Keyboard
	Ps2_Initialize();
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
