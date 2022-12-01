#include <stdio.h>

int binarySearch(long long int arr[], int tc, long long int find)
{
    int left = 1;
    int right = tc;
    int mid;

    while(left <= right)
    {
        mid = (right + left) / 2;
        if(arr[mid] == find)
        {
            return mid;
        }
        else if(arr[mid] <= find)
        {
            if(mid + 1 > tc || arr[mid + 1] > find)
            {
                return mid;
            }
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int cases;
    long long int arr[100005] = {0};
    arr[0]= 0;

    scanf("%d", &cases);
    for(int tc = 1; tc <= cases; tc++)
    {
        scanf("%lld", &arr[tc]);
        arr[tc] = arr[tc] + arr[tc - 1];
        //printf("%d--%d ", tc, arr[tc]);
    }

    int findNum; 
    long long num;
    scanf("%d", &findNum);     
    for(int tc = 1; tc <= findNum; tc++)
    {
        scanf("%lld", &num);
        printf("Case #%d: %d\n", tc, binarySearch(arr, cases, num));
    }

    return 0;
}