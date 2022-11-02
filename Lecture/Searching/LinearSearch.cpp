#include <stdio.h>

int linearSearch(int arr[], int n, int find)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == find)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    
    return 0;
}