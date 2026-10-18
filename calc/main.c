/*
 * 사칙연산 라이브러리 예제 (정적/공유 라이브러리용)
 * 사용법: ./calc_static 20 4
 */
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(int argc, char *argv[])
{
    int a = 20, b = 4;

    if (argc == 3) {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }

    printf("a = %d, b = %d\n", a, b);
    printf("add      : %d\n", add(a, b));
    printf("subtract : %d\n", subtract(a, b));
    printf("multiply : %d\n", multiply(a, b));
    printf("divide   : %.2f\n", divide(a, b));

    return 0;
}
