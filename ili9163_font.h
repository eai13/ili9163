#ifndef _ILI9163_FONTS_H_
#define _ILI9163_FONTS_H_

#include <stdint.h>


typedef struct{
    uint8_t width;
    uint8_t height;
    uint8_t h_spacing;
    uint8_t v_spacing;
    const uint8_t * data;
}fontlib_t;

typedef enum{
    FONT_TEXT_STRING        = 0x00,
    FONT_TEXT_AUTO_CR       = 0x01,

}text_format_t;

extern fontlib_t font_9x6;

void    Font_SetSpace(fontlib_t * font, uint8_t new_space);
uint8_t Font_GetSpace(fontlib_t * font);
void    Font_SetHorizontalSpacing(fontlib_t * font, uint8_t new_spacing);
uint8_t Font_GetHorizontalSpacing(fontlib_t * font);

#endif