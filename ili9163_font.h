#ifndef _ILI9163_FONTS_H_
#define _ILI9163_FONTS_H_

#include <stdint.h>

typedef struct ili9163_fontlib{
    uint8_t width;
    uint8_t height;
    uint8_t ** data;
}ili9163_fontlib_t;

typedef enum ili9163_symlib{
    ILI9163_FONT_9x6 = 0
}ili9163_symlib_t;

extern ili9163_fontlib_t font_9x6;

#endif