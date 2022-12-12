#include <stdio.h>

int main()
{
    int a = 5;
    int *b = &a;

    printf("Address of a: %d\n", &a);
    printf("Value of a: %d\n", a);
    printf("\n");
    printf("Address of b: %d\n", &b);
    printf("Value of b: %d\n", b);
    printf("Value of *b: %d\n", *b);

    return 0;
}