#include "ili9163_font.h"


uint8_t ili9163_font9x6[][9] = {
    { 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000 },   // space
    { 0b001000, 0b001000, 0b001000, 0b001000, 0b001000, 0b001000, 0b000000, 0b001000, 0b000000 },   // !
    { 0b010010, 0b010010, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000 },   // "
    { 0b010010, 0b010010, 0b111111, 0b010010, 0b010010, 0b111111, 0b010010, 0b010010, 0b000000 },   // #
    { 0b001100, 0b111110, 0b001101, 0b011110, 0b101100, 0b101100, 0b011111, 0b001100, 0b000000 },   // $
    { 0b000010, 0b100101, 0b010010, 0b001000, 0b000100, 0b010010, 0b101001, 0b010000, 0b000000 },   // %
    { 0b000110, 0b001001, 0b000001, 0b000010, 0b010111, 0b011001, 0b010001, 0b101110, 0b000000 },   // &
    { 0b001000, 0b001000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000 },   // '
    { 0b010000, 0b001000, 0b000100, 0b000100, 0b000100, 0b000100, 0b001000, 0b010000, 0b000000 },   // (
    { 0b000010, 0b000100, 0b001000, 0b001000, 0b001000, 0b001000, 0b000100, 0b000010, 0b000000 },   // )
    { 0b001000, 0b101010, 0b011100, 0b011100, 0b101010, 0b001000, 0b000000, 0b000000, 0b000000 },   // *
    { 0b000000, 0b001000, 0b001000, 0b001000, 0b111110, 0b001000, 0b001000, 0b001000, 0b000000 },   // +
    { 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b001100, 0b001000, 0b000100 },   // ,
    { 0b000000, 0b000000, 0b000000, 0b000000, 0b011110, 0b000000, 0b000000, 0b000000, 0b000000 },   // -
    { 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b001100, 0b001100, 0b000000 },   // .
    { 0b000000, 0b100000, 0b010000, 0b001000, 0b000100, 0b000010, 0b000001, 0b000000, 0b000000 },   // /
    { 0b011110, 0b100001, 0b100001, 0b100001, 0b100001, 0b100001, 0b100001, 0b011110, 0b000000 },   // 0
    { 0b001000, 0b001100, 0b001010, 0b001000, 0b001000, 0b001000, 0b001000, 0b001000, 0b000000 },   // 1
    { 0b011110, 0b100001, 0b100000, 0b010000, 0b001000, 0b000100, 0b000010, 0b111111, 0b000000 },   // 2
    { 0b001111, 0b010000, 0b010000, 0b011111, 0b100000, 0b100000, 0b100000, 0b011111, 0b000000 },   // 3
    { 0b100001, 0b100001, 0b100001, 0b111110, 0b100000, 0b100000, 0b100000, 0b100000, 0b000000 },   // 4
    { 0b111111, 0b000001, 0b000001, 0b011111, 0b100000, 0b100000, 0b100000, 0b011111, 0b000000 },   // 5
    { 0b011110, 0b000001, 0b000001, 0b011111, 0b100001, 0b100001, 0b100001, 0b011110, 0b000000 },   // 6
    { 0b111111, 0b100000, 0b100000, 0b010000, 0b001000, 0b000100, 0b000100, 0b000100, 0b000000 },   // 7
    { 0b011110, 0b100001, 0b100001, 0b011110, 0b100001, 0b100001, 0b100001, 0b011110, 0b000000 },   // 8
    { 0b011110, 0b100001, 0b100001, 0b100001, 0b111110, 0b100000, 0b100000, 0b011110, 0b000000 },   // 9
    { 0b000000, 0b001100, 0b001100, 0b000000, 0b000000, 0b001100, 0b001100, 0b000000, 0b000000 },   // :
    { 0b000000, 0b001100, 0b001100, 0b000000, 0b000000, 0b001100, 0b001000, 0b000100, 0b000000 },   // ;
    { 0b000000, 0b110000, 0b001100, 0b000010, 0b000001, 0b000010, 0b001100, 0b110000, 0b000000 },   // <
    { 0b000000, 0b000000, 0b111111, 0b000000, 0b000000, 0b111111, 0b000000, 0b000000, 0b000000 },   // =
    { 0b000000, 0b000011, 0b001100, 0b010000, 0b100000, 0b010000, 0b001100, 0b000011, 0b000000 },   // >
    { 0b011110, 0b100001, 0b100001, 0b100000, 0b011000, 0b000100, 0b000000, 0b000100, 0b000000 },   // ?
    { 0b011110, 0b100001, 0b111001, 0b100101, 0b100101, 0b111001, 0b000001, 0b011110, 0b000000 },   // @
    { 0b011110, 0b100001, 0b100001, 0b111111, 0b100001, 0b100001, 0b100001, 0b100001, 0b000000 },   // A
    { 0b001111, 0b010001, 0b010001, 0b011111, 0b100001, 0b100001, 0b100001, 0b011111, 0b000000 },   // B
    { 0b111110, 0b000001, 0b000001, 0b000001, 0b000001, 0b000001, 0b000001, 0b111110, 0b000000 },   // C
    { 0b011111, 0b100001, 0b100001, 0b100001, 0b100001, 0b100001, 0b100001, 0b011111, 0b000000 },   // D
    { 0b111111, 0b000001, 0b000001, 0b011111, 0b000001, 0b000001, 0b000001, 0b111111, 0b000000 },   // E
    { 0b111111, 0b000001, 0b000001, 0b011111, 0b000001, 0b000001, 0b000001, 0b000001, 0b000000 },   // F
    { 0b011110, 0b100001, 0b000001, 0b000001, 0b111001, 0b100001, 0b100001, 0b011110, 0b000000 },   // G
    { 0b100001, 0b100001, 0b100001, 0b111111, 0b100001, 0b100001, 0b100001, 0b100001, 0b000000 },   // H
    { 0b111110, 0b001000, 0b001000, 0b001000, 0b001000, 0b001000, 0b001000, 0b111110, 0b000000 },   // I
    { 0b111110, 0b100000, 0b100000, 0b100000, 0b100000, 0b100001, 0b100001, 0b011110, 0b000000 },   // J
    { 0b010001, 0b001001, 0b000101, 0b000011, 0b000101, 0b001001, 0b010001, 0b100001, 0b000000 },   // K
    { 0b000001, 0b000001, 0b000001, 0b000001, 0b000001, 0b100001, 0b100001, 0b111111, 0b000000 },   // L
    { 0b100001, 0b110011, 0b101101, 0b100001, 0b100001, 0b100001, 0b100001, 0b100001, 0b000000 },   // M
    { 0b100001, 0b100011, 0b100101, 0b101001, 0b110001, 0b100001, 0b100001, 0b100001, 0b000000 },   // N
    { 0b011110, 0b100001, 0b100001, 0b100001, 0b100001, 0b100001, 0b100001, 0b011110, 0b000000 },   // O
    { 0b011111, 0b100001, 0b100001, 0b100001, 0b011111, 0b000001, 0b000001, 0b000001, 0b000000 },   // P
    { 0b011110, 0b100001, 0b100001, 0b100001, 0b100001, 0b101001, 0b110001, 0b111110, 0b000000 },   // Q
    { 0b011111, 0b100001, 0b100001, 0b100001, 0b011111, 0b001001, 0b010001, 0b100001, 0b000000 },   // R
    { 0b011110, 0b100001, 0b000001, 0b011110, 0b100000, 0b100000, 0b100000, 0b011110, 0b000000 },   // S
    { 0b111110, 0b001000, 0b001000, 0b001000, 0b001000, 0b001000, 0b001000, 0b001000, 0b000000 },   // T
    { 0b100001, 0b100001, 0b100001, 0b100001, 0b100001, 0b100001, 0b100001, 0b011110, 0b000000 },   // U
    { 0b100001, 0b100001, 0b100001, 0b100001, 0b100001, 0b100001, 0b010010, 0b001100, 0b000000 },   // V
    { 0b100001, 0b100101, 0b100101, 0b100101, 0b100101, 0b100101, 0b100101, 0b011010, 0b000000 },   // W
    { 0b100001, 0b100001, 0b010010, 0b001100, 0b010010, 0b100001, 0b100001, 0b100001, 0b000000 },   // X
    { 0b100001, 0b100001, 0b100001, 0b100001, 0b111110, 0b100000, 0b100000, 0b011111, 0b000000 },   // Y
    { 0b111111, 0b100000, 0b010000, 0b001000, 0b000100, 0b000010, 0b000001, 0b111111, 0b000000 },   // Z
    { 0b011110, 0b000010, 0b000010, 0b000010, 0b000010, 0b000010, 0b000010, 0b011110, 0b000000 },   // [
    { 0b000000, 0b000001, 0b000010, 0b000100, 0b001000, 0b010000, 0b100000, 0b000000, 0b000000 },   /* \ */
    { 0b011110, 0b010000, 0b010000, 0b010000, 0b010000, 0b010000, 0b010000, 0b011110, 0b000000 },   // ]
    { 0b001100, 0b010010, 0b100001, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000 },   // ^
    { 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b111111, 0b000000 },   // _
    { 0b000010, 0b001100, 0b010000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000, 0b000000 },   // `
    { 0b000000, 0b000000, 0b011100, 0b100000, 0b111110, 0b100001, 0b100001, 0b011110, 0b000000 },   // a
    { 0b000001, 0b000001, 0b011111, 0b100001, 0b100001, 0b100001, 0b100001, 0b011110, 0b000000 },   // b
    { 0b000000, 0b000000, 0b111110, 0b000001, 0b000001, 0b000001, 0b000001, 0b111110, 0b000000 },   // c
    { 0b100000, 0b100000, 0b111110, 0b100001, 0b100001, 0b100001, 0b100001, 0b011110, 0b000000 },   // d
    { 0b000000, 0b000000, 0b011110, 0b100001, 0b100001, 0b011111, 0b000001, 0b011110, 0b000000 },   // e
    { 0b111000, 0b000100, 0b000100, 0b000100, 0b011111, 0b000100, 0b000100, 0b000100, 0b000000 },   // f
    { 0b000000, 0b000000, 0b011110, 0b100001, 0b100001, 0b011110, 0b010000, 0b010001, 0b001110 },   // g
    { 0b000001, 0b000001, 0b000001, 0b011111, 0b100001, 0b100001, 0b100001, 0b100001, 0b000000 },   // h
    { 0b000000, 0b000000, 0b001000, 0b000000, 0b001000, 0b001000, 0b001000, 0b001000, 0b000000 },   // i
    { 0b000000, 0b000000, 0b001000, 0b000000, 0b001000, 0b001000, 0b001000, 0b001001, 0b000110 },   // j
    { 0b000001, 0b000001, 0b001001, 0b000101, 0b001111, 0b010001, 0b010001, 0b010001, 0b000000 },   // k
    { 0b000110, 0b000100, 0b000100, 0b000100, 0b000100, 0b000100, 0b000100, 0b011000, 0b000000 },   // l
    { 0b000000, 0b000000, 0b011011, 0b100101, 0b100101, 0b100101, 0b100101, 0b100101, 0b000000 },   // m
    { 0b000000, 0b000000, 0b011111, 0b100001, 0b100001, 0b100001, 0b100001, 0b100001, 0b000000 },   // n
    { 0b000000, 0b000000, 0b011110, 0b100001, 0b100001, 0b100001, 0b100001, 0b011110, 0b000000 },   // o
    { 0b000000, 0b000000, 0b011110, 0b100001, 0b100001, 0b100001, 0b011111, 0b000001, 0b000001 },   // p
    { 0b000000, 0b000000, 0b011110, 0b100001, 0b100001, 0b100001, 0b111110, 0b100000, 0b100000 },   // q
    { 0b000000, 0b000000, 0b111110, 0b000001, 0b000001, 0b000001, 0b000001, 0b000001, 0b000000 },   // r
    { 0b000000, 0b000000, 0b111110, 0b000001, 0b011110, 0b100000, 0b100001, 0b011110, 0b000000 },   // s
    { 0b000100, 0b000100, 0b000100, 0b111110, 0b000100, 0b000100, 0b000100, 0b111000, 0b000000 },   // t
    { 0b000000, 0b000000, 0b100001, 0b100001, 0b100001, 0b100001, 0b100010, 0b111100, 0b000000 },   // u
    { 0b000000, 0b000000, 0b100001, 0b100001, 0b100001, 0b010010, 0b010010, 0b001100, 0b000000 },   // v
    { 0b000000, 0b000000, 0b100001, 0b100001, 0b100101, 0b100101, 0b100101, 0b011010, 0b000000 },   // w
    { 0b000000, 0b000000, 0b100001, 0b010010, 0b001100, 0b001100, 0b010010, 0b100001, 0b000000 },   // x
    { 0b000000, 0b000000, 0b100001, 0b100001, 0b100001, 0b100001, 0b111110, 0b100000, 0b011110 },   // y
    { 0b000000, 0b000000, 0b111111, 0b010000, 0b001000, 0b000100, 0b000010, 0b111111, 0b000000 },   // z
    { 0b011000, 0b000100, 0b000100, 0b000110, 0b000110, 0b000100, 0b000100, 0b011000, 0b000000 },   // {
    { 0b001000, 0b001000, 0b001000, 0b001000, 0b001000, 0b001000, 0b001000, 0b001000, 0b000000 },   // |
    { 0b000110, 0b001000, 0b001000, 0b011000, 0b011000, 0b001000, 0b001000, 0b000110, 0b000000 },   // }
    { 0b000000, 0b000000, 0b000110, 0b101101, 0b011000, 0b000000, 0b000000, 0b000000, 0b000000 }   // ~
};

ili9163_fontlib_t font_9x6 = {
    .height = 8,
    .width = 5,
    .data = ili9163_font9x6
};