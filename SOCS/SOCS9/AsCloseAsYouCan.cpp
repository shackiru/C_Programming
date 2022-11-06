#include <stdio.h>

int binarySearch(int *arr, int tc, int find)
{
    int left = 0;
    int right = tc;

    while(left <= right)
    {
        int mid = (right + left) / 2;
        if(find < arr[mid])
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    if(arr[left] == find)
    {
        left++;
    }
    return left;
}

int main()
{
    int cases;
    int arr[100005];

    scanf("%d", &cases);
    for(int tc = 0; tc < cases; tc++)
    {
        scanf("%d", &arr[tc]);
    }

    return 0;
}