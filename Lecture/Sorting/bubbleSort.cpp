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
    int a = 0;
    int flag = 0;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                Swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
            a++;
        }
        if(flag == 0)
        {
            break;
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
    Bubble(angka, N);
    for(int i = 0; i < 100; i++)
    {
        printf("%d ", angka[i]);
    }
    printf("\n");

    return 0;
}