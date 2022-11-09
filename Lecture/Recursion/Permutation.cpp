#include <stdio.h>

void printPerm(int *arr, int perm[], int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%d, ", arr[perm[i]]);
    }
    printf("\n");
}

void function(int *arr, int start, int end, int perm[], int n)
{
    for(int i = start; i <= end; i++)
    {
        perm[n] = i;
        printPerm(arr, perm, n + 1);
        function(arr, i + 1, end, perm, n + 1);
    }
}

int main()
{
    int arr[] = {1, 3, 5 ,7 ,9};
    int perm[105] = {};
    function(arr, 0, 4, perm, 0);
    
    return 0;
}