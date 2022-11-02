#include <stdio.h>

int partition(int *arr, int low, int high)
{
    
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


    return 0;
}