#include "ili9163.h"
#include "ili9163_font.h"
#include "debug.h"
#include "math.h"

#define _SWAP(x1, x2) \
            {  \
              uint8_t tmp = x1; \
              x1 = x2; \
              x2 = tmp; \
            }

#define _MIN(x1, x2) \
            (((x1) < (x2)) ? (x1) : (x2))

#define _MAX(x1, x2) \
            (((x1) < (x2)) ? (x2) : (x1))

inline void ILI9163_Init(ili9163_led_t * screen, SPI_HandleTypeDef * spi_hndl, GPIO_TypeDef * cs_port, uint16_t cs_pin, GPIO_TypeDef * a0_port, uint16_t a0_pin, GPIO_TypeDef * reset_port, uint16_t reset_pin){
    screen->hspi = spi_hndl;
    screen->cs_pin = cs_pin;
    screen->cs_port = cs_port;
    screen->a0_pin = a0_pin;
    screen->a0_port = a0_port;
    screen->reset_pin = reset_pin;
    screen->reset_port = reset_port;

    uint8_t parameter;

    ILI9163_SELECT(screen);

    ILI9163_HWReset(screen);

    ILI9163_WriteCommand(screen, ILI9163_CMD_SW_RESET);
    _DELAY(300);
    ILI9163_WriteCommand(screen, ILI9163_CMD_SLEEP_OUT);
    _DELAY(300);
    ILI9163_WriteCommand(screen, ILI9163_CMD_NORMAL_MODE_ON);
    _DELAY(300);
    ILI9163_WriteCommand(screen, ILI9163_CMD_DISPLAY_ON);
    _DELAY(300);

#ifdef PIXEL_FORMAT
    ILI9163_WriteCommand(screen, ILI9163_CMD_INTERFACE_PIXEL_FORMAT);
    parameter = PIXEL_FORMAT;
    ILI9163_WriteData(screen, &parameter, 1);
#endif

#ifdef COLOR_FORMAT
#ifdef WRITE_FORMAT
    ILI9163_WriteCommand(screen, ILI9163_CMD_MEMORY_ACCESS_CONTROL);
    parameter = COLOR_FORMAT | WRITE_FORMAT;
    ILI9163_WriteData(screen, &parameter, 1);
#endif
#endif

    ILI9163_DESELECT(screen);
}

inline void ILI9163_HWReset(ili9163_led_t * screen){
    // HAL_GPIO_WritePin(screen->reset_port, screen->reset_pin, 0);
    _RESET_PIN(screen->reset_port, screen->reset_pin);
    _DELAY(150);
    // HAL_GPIO_WritePin(screen->reset_port, screen->reset_pin, 1);
    _SET_PIN(screen->reset_port, screen->reset_pin);
}

inline void ILI9163_WriteCommand(ili9163_led_t * screen, ili9163_cmd_t command){
    ILI9163_COMMAND(screen);
    _SPI_TX(screen->hspi, &command, sizeof(uint8_t));
}

inline void ILI9163_WriteData(ili9163_led_t * screen, uint8_t * pdata, uint32_t size){
    ILI9163_DATA(screen);
    _SPI_TX(screen->hspi, pdata, size);
}

void ILI9163_WriteChar(ili9163_led_t * screen, uint8_t x, uint8_t y, uint8_t sym, fontlib_t * font,
                       ili9163_colors_t font_color, ili9163_colors_t background){
    x += ILI9163_COL_START;
    y += ILI9163_ROW_START;
    uint16_t start_elem = (sym - ' ') * (font->height);
    ILI9163_WriteCommand(screen, ILI9163_CMD_COLUMN_ADDRESS_SET);
    uint8_t col[4] = { 0, x, 0, x + font->width - 1 };
    ILI9163_WriteData(screen, col, sizeof(col));
    ILI9163_WriteCommand(screen, ILI9163_CMD_PAGE_ADDRESS_SET);
    uint8_t row[4] = { 0, y, 0, y + font->height - 1 };
    ILI9163_WriteData(screen, row, sizeof(row));

    ILI9163_WriteCommand(screen, ILI9163_CMD_MEMORY_WRITE);
    for (uint16_t r = 0; r < font->height; r++){
        for (uint16_t c = 0; c < font->width; c++){
            if (font->data[start_elem + r] & (1 << c))
                ILI9163_WriteData(screen, &font_color, 3);
            else
                ILI9163_WriteData(screen, &background, 3);
        }
    }
}

void ILI9163_WriteString(ili9163_led_t * screen, uint8_t x, uint8_t y, uint8_t * str, fontlib_t * font,
                         ili9163_colors_t font_color, ili9163_colors_t background, text_format_t text_format){
    uint8_t orig_x = x;
    uint8_t orig_y = y;
    while(1){
        ILI9163_WriteChar(screen, x, y, *(str++), font, font_color, background);
        x += font->width;
        if (*str == '\0') break;
        else ILI9163_Rect(screen, x, y, font->h_spacing, font->height, background, background, 1);
        x += font->h_spacing;
        if (text_format == FONT_TEXT_STRING){
            if (x + font->width >= ILI9163_SCREEN_WIDTH) return;
        }
        else if (text_format == FONT_TEXT_AUTO_CR){
            if (x + font->width >= ILI9163_SCREEN_WIDTH){
                if (y + font->height + font->v_spacing >= ILI9163_SCREEN_HEIGHT) return;
                y += font->height;
                ILI9163_Rect(screen, orig_x, y, x - orig_x, font->v_spacing, background, background, 1);
                y += font->v_spacing;
                x = orig_x;
            }
        }
    }
}

void ILI9163_Fill(ili9163_led_t * screen, ili9163_colors_t color){
    ILI9163_WriteCommand(screen, ILI9163_CMD_COLUMN_ADDRESS_SET);
    uint8_t col[4] = { 0, ILI9163_COL_START, 0, ILI9163_COL_START + 127 };
    ILI9163_WriteData(screen, col, sizeof(col));
    ILI9163_WriteCommand(screen, ILI9163_CMD_PAGE_ADDRESS_SET);
    uint8_t row[4] = { 0, ILI9163_ROW_START, 0, ILI9163_ROW_START + 127 };
    ILI9163_WriteData(screen, row, sizeof(row));

    ILI9163_WriteCommand(screen, ILI9163_CMD_MEMORY_WRITE);
    for (uint16_t iter = 0; iter < (128 * 128); iter++)
        ILI9163_WriteData(screen, &color, 3);
}

void ILI9163_Line(ili9163_led_t * screen, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2,
                  ili9163_colors_t color, uint8_t thickness){
    uint8_t col[4] = { 0, ILI9163_COL_START, 0, ILI9163_COL_START };
    uint8_t row[4] = { 0, ILI9163_ROW_START, 0, ILI9163_ROW_START };

    if (abs((int16_t)(x2) - (int16_t)(x1)) < abs((int16_t)(y2) - (int16_t)(y1))){
        float gain = ((float)(x2) - (float)(x1)) / ((float)_MAX(y1, y2) - (float)_MIN(y1, y2));
        float true_x = x1;
        for (uint8_t iter = y1; iter != y2; iter += ((y1 > y2) ? (-1) : (1))){
            col[1] = ILI9163_COL_START + (uint8_t)true_x - (thickness - 1); col[3] = ILI9163_COL_START + (uint8_t)true_x + (thickness - 1);
            row[1] = ILI9163_ROW_START + iter - (thickness - 1);            row[3] = ILI9163_ROW_START + (uint8_t)iter + (thickness - 1);
            ILI9163_WriteCommand(screen, ILI9163_CMD_COLUMN_ADDRESS_SET);
            ILI9163_WriteData(screen, col, sizeof(col));
            ILI9163_WriteCommand(screen, ILI9163_CMD_PAGE_ADDRESS_SET);
            ILI9163_WriteData(screen, row, sizeof(row));

            ILI9163_WriteCommand(screen, ILI9163_CMD_MEMORY_WRITE);
            for (uint8_t iter2 = 0; iter2 < ((thickness - 1) * 2 + 1) * ((thickness - 1) * 2 + 1); iter2++)
                ILI9163_WriteData(screen, &color, 3);

            true_x += gain;
        }
    }
    else{
        float gain = ((float)(y2) - (float)(y1)) / ((float)_MAX(x1, x2) - (float)_MIN(x1, x2));
        float true_y = y1;
        for (uint8_t iter = x1; iter != x2; iter += ((x1 > x2) ? (-1) : (1))){
            col[1] = ILI9163_COL_START + iter - (thickness - 1);            col[3] = ILI9163_COL_START + (uint8_t)iter + (thickness - 1);
            row[1] = ILI9163_ROW_START + (uint8_t)true_y - (thickness - 1); row[3] = ILI9163_ROW_START + (uint8_t)true_y + (thickness - 1);
            ILI9163_WriteCommand(screen, ILI9163_CMD_COLUMN_ADDRESS_SET);
            ILI9163_WriteData(screen, col, sizeof(col));
            ILI9163_WriteCommand(screen, ILI9163_CMD_PAGE_ADDRESS_SET);
            ILI9163_WriteData(screen, row, sizeof(row));

            ILI9163_WriteCommand(screen, ILI9163_CMD_MEMORY_WRITE);
            for (uint8_t iter2 = 0; iter2 < ((thickness - 1) * 2 + 1) * ((thickness - 1) * 2 + 1); iter2++)
                ILI9163_WriteData(screen, &color, 3);

            true_y += gain;
        }    
    }
}

void ILI9163_Rect(ili9163_led_t * screen, uint8_t x, uint8_t y, uint8_t width, uint8_t height,
                  ili9163_colors_t border_color, ili9163_colors_t fill_color, uint8_t fill_flag){
    if (fill_flag){
        ILI9163_WriteCommand(screen, ILI9163_CMD_COLUMN_ADDRESS_SET);
        uint8_t col[4] = { 0, ILI9163_COL_START + x, 0, ILI9163_COL_START + width + x - 1 };
        ILI9163_WriteData(screen, col, sizeof(col));
        ILI9163_WriteCommand(screen, ILI9163_CMD_PAGE_ADDRESS_SET);
        uint8_t row[4] = { 0, ILI9163_ROW_START + y, 0, ILI9163_ROW_START + height + y - 1 };
        ILI9163_WriteData(screen, row, sizeof(row));

        ILI9163_WriteCommand(screen, ILI9163_CMD_MEMORY_WRITE);
        for (uint8_t row = 0; row < height; row++){
            for (uint8_t col = 0; col < width; col++){
                if ((col == 0) || (col == (width - 1)) || (row == 0) || (row == (height - 1)))
                    ILI9163_WriteData(screen, &border_color, 3);
                else
                    ILI9163_WriteData(screen, &fill_color, 3);
            }
        }
    }
    else{
        ILI9163_Line(screen, x, y, x + width, y, border_color, 1);
        ILI9163_Line(screen, x, y, x, y + height, border_color, 1);
        ILI9163_Line(screen, x + width, y, x + width, y + height, border_color, 1);
        ILI9163_Line(screen, x, y + height, x + width, y + height, border_color, 1);
    }
}

void ILI9163_Circ(ili9163_led_t * screen, uint8_t x, uint8_t y, int8_t radius,
                  ili9163_colors_t border_color, uint8_t border_thick, ili9163_colors_t fill_color, uint8_t fill_flag){
    uint8_t x_old = x + radius;
    uint8_t x_new = 0;
    uint8_t y_old = y;
    uint8_t y_new = 0;
    for (uint16_t iter = 1; iter < 361; iter += 1){
        x_new = cos(3.14 * (double)(iter) / (double)(180)) * radius + x;
        y_new = sin(3.14 * (double)(iter) / (double)(180)) * radius + y;
        ILI9163_Line(screen, x_old, y_old, x_new, y_new, border_color, border_thick);
        x_old = x_new;
        y_old = y_new;
    }
    ILI9163_Line(screen, x_old, y_old, x + radius, y, border_color, border_thick);
    if (fill_flag){
        ILI9163_Circ(screen, x, y, radius / 2, fill_color, 10, fill_color, 0);
    }
}