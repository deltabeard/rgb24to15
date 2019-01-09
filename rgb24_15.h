#include <stdint.h>

uint16_t convert(uint32_t rgb24)
{
	uint16_t out = (((rgb24 & 0x0000FF) >> 3) & 0x001F) |
		(((rgb24 & 0x00FF00) >> 6) & 0x03E0) |
		(((rgb24 & 0xFF0000) >> 9) & 0x7C00);
	return out;
}

