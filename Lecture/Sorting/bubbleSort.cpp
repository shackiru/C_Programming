#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define N 1000

int main()
{
    int angka[N + 5];
    for(int i = 0; i < N; i ++)
    {
        angka[i] = (rand() % 100) + 1;
    }

    std::sort(angka, angka + 10);
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", angka[i]);
    }

    return 0;
}