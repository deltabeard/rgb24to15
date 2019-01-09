#define RGB24_TO_15(x) ((((x & 0x0000FF) >> 3) & 0x001F) | \
		(((x & 0x00FF00) >> 6) & 0x03E0) | \
		(((x & 0xFF0000) >> 9) & 0x7C00))

short rgb24_to_15(long int rgb24)
{
	return (((rgb24 & 0x0000FF) >> 3) & 0x001F) |
		(((rgb24 & 0x00FF00) >> 6) & 0x03E0) |
		(((rgb24 & 0xFF0000) >> 9) & 0x7C00);
}

