#ifndef CHARCO_H
#define CHARCO_H

#include <stdio.h> // printf
#include <stdlib.h> // int types
#include <locale.h> // setlocale
#include "args.h" // arguments
#include "utf8.h" // utf8_decode
#include "utf16.h" // utf16_encode

typedef struct {
	uint8_t ch;
	uint32_t utf8;
	uint32_t utf16;
} charco_t;

#endif // CHARCO_H
