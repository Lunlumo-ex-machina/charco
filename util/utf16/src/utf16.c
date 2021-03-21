#include "utf16.h"

uint32_t utf16_encode(uint32_t ch) {
	if (ch <= 0xFFFF) {
		return ch;
	}
	ch -= 0x10000;
	return ((ch % 0x400) + 0xDC00) | (((ch / 0x400) + 0xD800) << 16);
}
