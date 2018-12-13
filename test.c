#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "parity.h"

double tvgetf()
{
    struct timespec ts;
    double sec;

    clock_gettime(CLOCK_REALTIME, &ts);
    sec = ts.tv_nsec;

    return sec;
}

void parityTest()
{
    FILE *file = fopen("parity.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    uint32_t x;
    double tm;
    int parity_bit;

    for (int i = 0; i < 100; ++i) {
        x = (uint32_t) i;
        tm = tvgetf();
        parity_bit = parityGen(x);
        tm -= tvgetf();
        fprintf(file, "%u %f\n", x, -tm);
    }
    fclose(file);
}

int main(int argc, char *argv[])
{
    switch (*argv[1]) {
    case '1':
        printf("parity test start\n");
        parityTest();
        printf("end test\n");
        break;
    default:
        printf("no test\n");
        break;
    }
    return 0;
}
