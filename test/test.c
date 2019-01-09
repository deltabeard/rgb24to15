#include "../rgb24_15.h"
#include "minctest.h"

void test1(void)
{
     lequal(convert(0xFFFFFF), 0x7FFF);
     lequal(convert(0x010101), 0x0000);
     lequal(convert(0x101010), 0x0842);
     lequal(convert(0xFFFF00), 0x7FE0);
}

int main(void) {
     lrun("Conversion tests", test1);
     lresults();
     return lfails != 0;
}
