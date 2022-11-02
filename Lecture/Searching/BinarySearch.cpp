#include <stdio.h>

int binarySearch(int *arr, int n, int find)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;
        if(arr[mid] == find)
        {
            return mid;
        }
        else if(find < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

int main()
{


    return 0;
}