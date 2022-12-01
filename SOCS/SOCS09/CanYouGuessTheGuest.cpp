#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int index = low - 1;

    for(int i = low + 1; i < high; i++)
    {
        if(arr[i] < pivot)
        {
            swap(&arr[index], &arr[i]);
            index++;
        }
        swap(&arr[low], &arr[index - 1]);
        return index - 1;
    } 
}

int quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
}