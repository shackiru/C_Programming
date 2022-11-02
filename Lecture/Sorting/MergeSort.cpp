#include <stdio.h>
#include <stdlib.h>
#define n 1000

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void merge(int *arr, int left, int mid, int right)
{
    int temp[right - left + 5];

    for(int i = left; i <= right; i++)
    {
        temp[i - left] = arr[i];
    }
    int indexLeft = 0;
    int indexRight = mid - left + 1;
    int indexArray = left;

    while(indexLeft < mid - left && indexRight <= right - left)
    {
        if (temp[indexLeft] < temp[indexRight])
        {
            arr[indexArray] = temp[indexLeft];
            indexLeft++;
        }
        else
        {
            arr[indexArray] = temp[indexRight];
            indexRight++;
        }
        indexArray++;
    }

    while(indexLeft <= mid - left)
    {
        arr[indexArray++] = temp[indexLeft++];
    }

    while(indexRight <= right - mid)
    {
        arr[indexArray++] = temp[indexRight++];
    }
}

void mergeSort(int *arr, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[n + 5];
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }
    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
