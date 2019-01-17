#include "num4.h"

int func()
{
    char c[4];
    unsigned int i = 0x12345678;
    memcpy(c, &i, sizeof(i));
    printf("0x%x  0x%x  0x%x  0x%x\n", c[0], c[1], c[2], c[3]);
}
