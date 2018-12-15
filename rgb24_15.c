/**
 * This is free and unencumbered software released into the public domain.
 * 
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 * 
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 * 
 * For more information, please refer to <http://unlicense.org>
*/

#include <math.h>

#include <string.h>
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

	if(argc < 2)
	{
		printf("Converts 24-bit RGB to 15-bit RGB colour values.\n"
			"Usage: %s HEX...\n",
			argv[0]);
		exit(EXIT_FAILURE);
	}

	for(int i = 1; i < argc; i++)
	{
		if(strlen(argv[i]) != strlen("0xFFFFFF"))
		{
			printf("0xXXXX ");
			continue;
		}

		input.colour_24 = strtol(argv[i], NULL, 16);

		output.colour_15 = 0;
		output.b = (double)input.b * MULTIPLICATION_RATIO;
		output.g = (double)input.g * MULTIPLICATION_RATIO;
		output.r = (double)input.r * MULTIPLICATION_RATIO;

		printf("0x%04X ", output.colour_15);
	}

	printf("\n");
	return 0;
}
