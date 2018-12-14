#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "parity.h"

#define REPEAT 20
#define INIT_VAL 1000000
#define END_VAL 1000020

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
    FILE *file1 = fopen("parity_heatmap.txt", "w");
    if (file1 == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }
    uint32_t x;
    double tm;
    int parity_bit;

    for (int i = 0; i < REPEAT; i++) {
        for (int j = INIT_VAL; j < END_VAL; j++) {
            x = (uint32_t) j;
            tm = tvgetf();
            parity_bit = parityGen(x);
            tm -= tvgetf();
            fprintf(file1, "%d %d %f\n", i, j, -tm);
        }
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
