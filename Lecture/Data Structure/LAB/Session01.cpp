#include <stdio.h>

int main()
{
    int a = 5;
    int *b = &a;
    int **c = &b;

    printf("Address of a\t: %d\n", &a);
    printf("Value of a\t: %d\n", a);
    printf("\n");

    printf("Address of b\t: %d\n", &b);
    printf("Value of b\t: %d\n", b);
    printf("Value of *b\t: %d\n", *b);
    printf("\n");

    printf("Address of c\t: %d\n", &c);
    printf("Value of c\t: %d\n", c);
    printf("Value of *c\t: %d\n", *c);
    printf("Value of **c\t: %d\n", **c);
    printf("\n");

    int scores[] = {100, 90, 95, 80};
    int size = sizeof(scores) / sizeof(scores[0]);
    for(int i = 0; i < size; i++)
    {
        printf("Index %d: %d - %d\n", i + 1, &scores[i], scores[i]);
    }

    return 0;
}
