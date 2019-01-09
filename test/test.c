#include "../rgb24_15.h"
#include "minctest.h"

void test1(void)
{
     lequal(rgb24_to_15(0xFFFFFF), 0x7FFF);
     lequal(rgb24_to_15(0x010101), 0x0000);
     lequal(rgb24_to_15(0x101010), 0x0842);
     lequal(rgb24_to_15(0xFFFF00), 0x7FE0);
}

void test2(void)
{
     lequal(RGB24_TO_15(0xFFFFFF), 0x7FFF);
     lequal(RGB24_TO_15(0x010101), 0x0000);
     lequal(RGB24_TO_15(0x101010), 0x0842);
     lequal(RGB24_TO_15(0xFFFF00), 0x7FE0);
}

int main(void) {
     lrun("Function tests", test1);
     lrun("Macro tests", test2);
     lresults();
     return lfails != 0;
}
