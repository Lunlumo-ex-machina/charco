#include "utf8.h"

uint8_t utf8_ch_len(uint32_t ch) {
	uint8_t len = 0;
	for (;ch; len++, ch >>= 8);
	return len;
}

uint32_t utf8_decode(uint32_t ch) {
	uint32_t mask = 0;
	int len = utf8_ch_len(ch);
	if (len == 1) {
		return ch;
	}
	for (int i = 0; i < len-1; i++) {
		mask |= 0x80 << (8 * i);
	}
	mask |= ((0xFF ^ ((1 << (8-len))-1)) << (8*(len-1)));
	ch ^= mask;
	uint32_t result = 0;
	for (int i = 0; i < len-1; i++) {
		result |= (ch & 0x3F) << (6 * i);
		ch >>= 8;
	}
	result |= ch << (6 * (len-1));
	return result;
}
