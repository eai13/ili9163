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
    // HAL_GPIO_WritePin(screen->a0_port, screen->a0_pin, 0);
    _RESET_PIN(screen->a0_port, screen->a0_pin);
}
inline void ILI9163_DATA(ili9163_led_t * screen){
    // HAL_GPIO_WritePin(screen->a0_port, screen->a0_pin, 1);
    _SET_PIN(screen->a0_port, screen->a0_pin);
}

inline void ILI9163_SELECT(ili9163_led_t * screen){
    // HAL_GPIO_WritePin(screen->cs_port, screen->cs_pin, 0);
    _RESET_PIN(screen->cs_port, screen->cs_pin);
}
inline void ILI9163_DESELECT(ili9163_led_t * screen){
    // HAL_GPIO_WritePin(screen->cs_port, screen->cs_pin, 1);
    _SET_PIN(screen->cs_port, screen->cs_pin);
}

void ILI9163_HWReset(ili9163_led_t * screen);
void ILI9163_WriteCommand(ili9163_led_t * screen, ili9163_cmd_t command);
void ILI9163_WriteData(ili9163_led_t * screen, uint8_t * pdata, uint32_t size);

void ILI9163_WriteChar(ili9163_led_t * screen, uint8_t x, uint8_t y, uint8_t sym, ili9163_fontlib_t font,
                       ili9163_colors_t font_color, ili9163_colors_t background);

void ILI9163_Init(ili9163_led_t * screen, SPI_HandleTypeDef * hspi, GPIO_TypeDef * cs_port, uint16_t cs_pin, GPIO_TypeDef * a0_port, uint16_t a0_pin, GPIO_TypeDef * reset_port, uint16_t reset_pin);

#endif