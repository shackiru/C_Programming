#include <stdio.h>
#include <stdlib.h>
#define N 1000

void Selection(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for(int j = i; j < n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        // swap
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

int main()
{
    int num[N + 5];
    for(int i = 0; i < N; i++)
    {
        num[i] = (rand() % 100) + 1;
        printf("%d ", num[i]);
    }
    printf("\n");

    Selection(num, N);
    for(int i = 0; i < N; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}
