#ifndef UTF8_H
#define UTF8_H

#include <stdint.h> // int types

uint8_t utf8_ch_len(uint32_t ch);
uint32_t utf8_decode(uint32_t ch);

#endif // UTF8_H
