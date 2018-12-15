#include <math.h>

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_5_BIT 32.0
#define MAX_8_BIT 256.0

#define MULTIPLICATION_RATIO (MAX_5_BIT/MAX_8_BIT)

int main(int argc, char** argv)
{
	union {
		struct {
			unsigned int b:8;
			unsigned int g:8;
			unsigned int r:8;
			unsigned int unused:8;
		};

		uint32_t colour_24;
	} input;
	union {
		struct {
			unsigned int b:5;
			unsigned int g:5;
			unsigned int r:5;
			unsigned int unused:1;
		};

		uint16_t colour_15;
	} output;

	if(argc != 2)
	{
		printf("Converts 24-bit RGB to 15-bit RGB colour values.\n"
			"Usage: %s hex\n",
			argv[0]);
		exit(EXIT_FAILURE);
	}

	input.colour_24 = strtol(argv[1], NULL, 16);

	output.colour_15 = 0;
	output.b = (double)input.b * MULTIPLICATION_RATIO;
	output.g = (double)input.g * MULTIPLICATION_RATIO;
	output.r = (double)input.r * MULTIPLICATION_RATIO;

	printf("0x%04X\n", output.colour_15);
	return 0;
}
