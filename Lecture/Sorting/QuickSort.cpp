#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int x = (rand() % (high - low + 1)) + low;

    swap(&arr[low], &arr[x]);
    
    int pivot = arr[low];
    int index = low + 1;

    for(int i = low + 1; i <= high; i++)
    {
        if(arr[i] < pivot)
        {
            swap(&arr[index], &arr[i]);
            index++;        }
    }
    swap(&arr[low], &arr[index - 1]);
    return index - 1;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1); // Left Partition
        quickSort(arr, pivot + 1, high); // Right Partition
    }
}

int main()
{
    int arr[1005];

    for(int i = 0; i < 1000; i++)
    {
        arr[i] = rand() % 1000 + 1;
    }

    quickSort(arr, 0, 1000 - 1);

    for(int i = 0; i < 1000; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
