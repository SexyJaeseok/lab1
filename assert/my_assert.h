#ifndef MY_ASSERT_H
#define MY_ASSERT_H

#include <stdio.h>
#include <stdlib.h>

#ifdef NDEBUG
#define my_assert(expr) ((void)0)
#else
void my_assert_fail(const char *expr, const char *file, int line, const char *func);

#define my_assert(expr) \
    ((expr) ? (void)0 : my_assert_fail(#expr, __FILE__, __LINE__, __func__))
#endif

#endif
