#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arr = (int*)malloc(sizeof(int) * 20);

    for(int i = 0; i < 10; i++)
    {
        arr[i] = 1 << i;
    }

    for(int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);           
    }
    printf("\n");

    return 0;
}