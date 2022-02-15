#ifndef _ILI9163_H_
#define _ILI9163_H_

#include "ili9163_config.h"
#include "ili9163_font.h"
#include "ili9163_settings.h"
#include "spi.h"
#include "stm32g0xx_hal.h"

#define _SET_PIN(port, pin)         HAL_GPIO_WritePin(port, pin, 1)
#define _RESET_PIN(port, pin)       HAL_GPIO_WritePin(port, pin, 0)
#define _SPI_TX(spi, pdata, size)   HAL_SPI_Transmit(spi, pdata, size, 200)
#define _DELAY(ms)                  HAL_Delay(ms)

typedef struct ili9163_led{
    SPI_HandleTypeDef * hspi;
    GPIO_TypeDef * cs_port;
    uint16_t cs_pin;
    GPIO_TypeDef * a0_port;
    uint16_t a0_pin;
    GPIO_TypeDef * reset_port;
    uint16_t reset_pin;
}ili9163_led_t;

inline void ILI9163_COMMAND(ili9163_led_t * screen){
    _RESET_PIN(screen->a0_port, screen->a0_pin);
}
inline void ILI9163_DATA(ili9163_led_t * screen){
    _SET_PIN(screen->a0_port, screen->a0_pin);
}

inline void ILI9163_SELECT(ili9163_led_t * screen){
    _RESET_PIN(screen->cs_port, screen->cs_pin);
}
inline void ILI9163_DESELECT(ili9163_led_t * screen){
    _SET_PIN(screen->cs_port, screen->cs_pin);
}

void ILI9163_HWReset(ili9163_led_t * screen);
void ILI9163_WriteCommand(ili9163_led_t * screen, ili9163_cmd_t command);
void ILI9163_WriteData(ili9163_led_t * screen, uint8_t * pdata, uint32_t size);

void ILI9163_WriteChar(ili9163_led_t * screen, uint8_t x, uint8_t y, uint8_t sym, fontlib_t * font,
                       ili9163_colors_t font_color, ili9163_colors_t background);

void ILI9163_WriteString(ili9163_led_t * screen, uint8_t x, uint8_t y, uint8_t * str, fontlib_t * font,
                         ili9163_colors_t font_color, ili9163_colors_t background, text_format_t text_format);

void ILI9163_Fill(ili9163_led_t * screen, ili9163_colors_t color);

void ILI9163_Rect(ili9163_led_t * screen, uint8_t x, uint8_t y, uint8_t width, uint8_t height,
                  ili9163_colors_t border_color, ili9163_colors_t fill_color, uint8_t fill_flag);

void ILI9163_Line(ili9163_led_t * screen, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2,
                  ili9163_colors_t color, uint8_t thickness);

void ILI9163_Circ(ili9163_led_t * screen, uint8_t x, uint8_t y, int8_t radius,
                  ili9163_colors_t border_color, uint8_t border_thick, ili9163_colors_t fill_color, uint8_t fill_flag);

void ILI9163_Init(ili9163_led_t * screen, SPI_HandleTypeDef * hspi, GPIO_TypeDef * cs_port, uint16_t cs_pin, GPIO_TypeDef * a0_port, uint16_t a0_pin, GPIO_TypeDef * reset_port, uint16_t reset_pin);

#endif