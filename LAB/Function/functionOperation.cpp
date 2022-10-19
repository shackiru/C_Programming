#include <stdio.h>

int addition(int a, int b)
{
    return a+b;
}

int addition(int a, int b, int *result)
{
    *result = a + b;
    return 0;
}

int main()
{
    int result = addition (2,3);
    printf("Result = %d\n", result);
    printf("Result = %d\n", &result);

    return 0;
}
