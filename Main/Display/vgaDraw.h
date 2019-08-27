#ifndef VGA_DRAW_H
#define VGA_DRAW_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void vga_draw_impl(uint8_t* pix, uint32_t* attr_base, uint8_t* attr, volatile uint8_t* odr);

#ifdef __cplusplus
}
#endif

#endif  // DRAW4_H
