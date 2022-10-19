#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define N 1000

void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                Swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    int angka[N + 5];
    for(int i = 0; i < N; i ++)
    {
        angka[i] = (rand() % 100) + 1;
    }

//    std::sort(angka, angka + 10);
    for(int i = 0; i < 10; i++)
    {
        printf("%d\n", angka[i]);
    }

    return 0;
}