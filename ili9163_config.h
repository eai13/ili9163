#ifndef _ILI9163_CONFIG_H_
#define _ILI9163_CONFIG_H_

#include <stdint.h>
#include "main.h"

#define ILI9136_SPI     hspi1
#define ILI9163_A0_PIN  A0_Pin
#define ILI9163_A0_PORT A0_GPIO_Port
#define ILI9163_CS_PIN  CS_Pin
#define ILI9163_CS_PORT CS_GPIO_Port

#define ILI9163_COL_START       2
#define ILI9163_ROW_START       1
#define ILI9163_SCREEN_WIDTH    128
#define ILI9163_SCREEN_HEIGHT   128

typedef enum ili9163_cmd{
    ILI9163_CMD_NOP                                 = (uint8_t)0x00,
    ILI9163_CMD_SW_RESET                            = (uint8_t)0x01,
    ILI9163_CMD_RD_ID                               = (uint8_t)0x04,
    ILI9163_CMD_GET_RED_CHANNEL                     = (uint8_t)0x06,
    ILI9163_CMD_GET_GREEN_CHANNEL                   = (uint8_t)0x07,
    ILI9163_CMD_GET_BLUE_CHANNEL                    = (uint8_t)0x08,
    ILI9163_CMD_RD_ST                               = (uint8_t)0x09,
    ILI9163_CMD_RD_POW_MOD                          = (uint8_t)0x0A,
    ILI9163_CMD_RD_MADCTL                           = (uint8_t)0x0B,
    ILI9163_CMD_RD_COLOR_MODE                       = (uint8_t)0x0C,
    ILI9163_CMD_RD_IMAGE_MODE                       = (uint8_t)0x0D,
    ILI9163_CMD_RD_SIGNAL_MODE_1                    = (uint8_t)0x0E,
    ILI9163_CMD_RD_SIGNAL_MODE_2                    = (uint8_t)0x0F,
    ILI9163_CMD_SLEEP_IN                            = (uint8_t)0x10,
    ILI9163_CMD_SLEEP_OUT                           = (uint8_t)0x11,
    ILI9163_CMD_PARTIAL_MODE_ON                     = (uint8_t)0x12,
    ILI9163_CMD_NORMAL_MODE_ON                      = (uint8_t)0x13,
    ILI9163_CMD_INVERSION_OFF                       = (uint8_t)0x20,
    ILI9163_CMD_INVERSION_ON                        = (uint8_t)0x21,
    ILI9163_CMD_GAMMA_SET                           = (uint8_t)0x26,
    ILI9163_CMD_DISPLAY_OFF                         = (uint8_t)0x28,
    ILI9163_CMD_DISPLAY_ON                          = (uint8_t)0x29,
    ILI9163_CMD_COLUMN_ADDRESS_SET                  = (uint8_t)0x2A,
    ILI9163_CMD_PAGE_ADDRESS_SET                    = (uint8_t)0x2B,
    ILI9163_CMD_MEMORY_WRITE                        = (uint8_t)0x2C,
    ILI9163_CMD_COLOR_SETTING                       = (uint8_t)0x2D,
    ILI9163_CMD_MEMORY_READ                         = (uint8_t)0x2E,
    ILI9163_CMD_PARTIAL_AREA                        = (uint8_t)0x30,
    ILI9163_CMD_VERTICAL_SCROLLING_DEFINITION       = (uint8_t)0x33,
    ILI9163_CMD_TEARING_EFFECT_LINE_OFF             = (uint8_t)0x34,
    ILI9163_CMD_TEARING_EFFECT_LINE_ON              = (uint8_t)0x35,
    ILI9163_CMD_MEMORY_ACCESS_CONTROL               = (uint8_t)0x36,
    ILI9163_CMD_VERTICAL_SCROLLING_START_ADDRESS    = (uint8_t)0x37,
    ILI9163_CMD_IDLE_MODE_OFF                       = (uint8_t)0x38,
    ILI9163_CMD_IDLE_MODE_ON                        = (uint8_t)0x39,
    ILI9163_CMD_INTERFACE_PIXEL_FORMAT              = (uint8_t)0x3A,
    ILI9163_CMD_FRAME_RATE_CONTROL_NORMAL_MODE      = (uint8_t)0xB1,
    ILI9163_CMD_FRAME_RATE_CONTROL_IDLE_MODE        = (uint8_t)0xB2,
    ILI9163_CMD_FRAME_RATE_CONTROL_PARTIAL_MODE     = (uint8_t)0xB3,
    ILI9163_CMD_DISPLAY_INVERSION_CONTROL           = (uint8_t)0xB4,
    ILI9163_CMD_SOURCE_DRIVER_DIRECTION_CONTROL     = (uint8_t)0xB7,
    ILI9163_CMD_GATE_DRIVER_DIRECTION_CONTROL       = (uint8_t)0xB8,
    ILI9163_CMD_POWER_CONTROL1                      = (uint8_t)0xC0,
    ILI9163_CMD_POWER_CONTROL2                      = (uint8_t)0xC1,
    ILI9163_CMD_POWER_CONTROL3                      = (uint8_t)0xC2,
    ILI9163_CMD_POWER_CONTROL4                      = (uint8_t)0xC3,
    ILI9163_CMD_POWER_CONTROL5                      = (uint8_t)0xC4,
    ILI9163_CMD_VCOM_CONTROL1                       = (uint8_t)0xC5,
    ILI9163_CMD_VCOM_CONTROL2                       = (uint8_t)0xC6,
    ILI9163_CMD_VCOM_OFFSET_CONTROL                 = (uint8_t)0xC7,
    ILI9163_CMD_WRITE_ID4_VALUE                     = (uint8_t)0xD3,
    ILI9163_CMD_NV_MEMORY_FUNCTION_CONTROLLER1      = (uint8_t)0xD7,
    ILI9163_CMD_READ_ID1                            = (uint8_t)0xDA,
    ILI9163_CMD_READ_ID2                            = (uint8_t)0xDB,
    ILI9163_CMD_READ_ID3                            = (uint8_t)0xDC,
    ILI9163_CMD_NV_MEMORY_FUNCTION_CONTROLLER2      = (uint8_t)0xDE,
    ILI9163_CMD_POSITIVE_GAMMA_CORRECTION_SETTING   = (uint8_t)0xE0,
    ILI9163_CMD_NEGATIVE_GAMMA_CORRECTION_SETTING   = (uint8_t)0xE1,
    ILI9163_CMD_GAMMA_SETTING_GREEN                 = (uint8_t)0xF2
}ili9163_cmd_t;

typedef enum ili9163_pix_format{
    PIX_FORMAT_12BIT = (uint8_t)0b00000011,
    PIX_FORMAT_16BIT = (uint8_t)0b00000101,
    PIX_FORMAT_18BIT = (uint8_t)0b00000110,
    PIX_FORMAT_DEFAULT = PIX_FORMAT_18BIT
}ili9163_pix_format_t;

typedef enum ili9163_color_filter{
    COLOR_FILTER_RGB = (uint8_t)(0x00),
    COLOR_FILTER_BGR = (uint8_t)(1 << 3)
}ili9163_color_filter_t;

typedef enum ili9163_write_direction{
    FROM_BOTTOM     = (uint8_t)(0x00),
    FROM_TOP        = (uint8_t)(1 << 7),
    LEFT_TO_RIGHT   = (uint8_t)(0x00),
    RIGHT_TO_LEFT   = (uint8_t)(1 << 6),
    FLIP_OFF        = (uint8_t)(0x00),
    FLIP_ON         = (uint8_t)(1 << 5)
}ili9163_write_direction_t;

#endif