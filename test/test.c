#include "../rgb24_15.h"
#include "minctest.h"

void test1(void)
{
     lequal(RGB888_TO_RGB555(0xFFFFFF), 0x7FFF);
     lequal(RGB888_TO_RGB555(0x010101), 0x0000);
     lequal(RGB888_TO_RGB555(0x101010), 0x0842);
     lequal(RGB888_TO_RGB555(0xFFFF00), 0x7FE0);
}

int main(void) {
     lrun("Tests", test1);
     lresults();
     return lfails != 0;
}
