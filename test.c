#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "num4.h"

#define REPEAT 1000
#define INIT_VAL 0
#define END_VAL 20

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
    FILE *file1 = fopen("num4_heatmap.txt", "w");
    if (file1 == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    uint32_t x;
    double tm;
    int parity_bit;

    for (int i = 0; i < REPEAT; i++) {
        tm = tvgetf();
        parity_bit = func();
        tm -= tvgetf();
        fprintf(file1, "%d %f\n", i, -tm);
    }
    fclose(file1);
}

int main(int argc, char *argv[])
{
    if (argc == 1) {
        printf("no args\n");
        return 0;
    }
    switch (*argv[1]) {
    case '1':
        parityTest();
        break;
    default:
        printf("no test\n");
        break;
    }
    return 0;
}
