/*
 * 동적 라이브러리 사용 (dlopen)
 */
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{
    void *handle;
    int (*add)(int, int);
    int (*subtract)(int, int);
    int (*multiply)(int, int);
    double (*divide)(int, int);
    char *error;
    int a = 20, b = 4;

    if (argc == 3) {
        a = atoi(argv[1]);
        b = atoi(argv[2]);
    }

    handle = dlopen("./lib/libcalc.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    add = dlsym(handle, "add");
    subtract = dlsym(handle, "subtract");
    multiply = dlsym(handle, "multiply");
    divide = dlsym(handle, "divide");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    printf("a = %d, b = %d\n", a, b);
    printf("add      : %d\n", add(a, b));
    printf("subtract : %d\n", subtract(a, b));
    printf("multiply : %d\n", multiply(a, b));
    printf("divide   : %.2f\n", divide(a, b));

    dlclose(handle);
    return 0;
}
