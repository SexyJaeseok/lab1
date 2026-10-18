#include <stdio.h>
#include "calc.h"

double divide(int a, int b)
{
    if (b == 0) {
        fprintf(stderr, "divide: 0으로 나눌 수 없습니다.\n");
        return 0.0;
    }
    return (double)a / b;
}
