/*
 * 5장 디버깅과 오류처리 - assert_test.c
 * assert()를 직접 구현한 my_assert()로 대체
 */

#include <stdio.h>
#include <stdlib.h>
#include "my_assert.h"

void foo(int num)
{
    my_assert( ((num >= 0) && (num <= 100)) );

    printf("foo: num = %d\n", num);
}

int main(int argc, char *argv[])
{
    int num;

    if (argc < 2) {
        fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber <= 100)\n");
        exit(1);
    }

    num = atoi(argv[1]);
    foo(num);
    return 0;
}
