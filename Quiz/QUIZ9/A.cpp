#include "stdio.h"
#define LL long long int
#define input scanf
#define display printf
#define lld "%lld"
#define d "%d"
int binarySearch(LL arr[], int left, int right, LL x, int n)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            if ((mid + 1 <= n) && (arr[mid + 1] > x))
            {
                return mid;
            }
            else if (mid + 1 > n)
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
    int inputnum1;
    input(d, &inputnum1);
    LL values[inputnum1 + 1] = {};
    LL temp;
    for (int i = 1; i <= inputnum1; i++)
    {
        input(lld, &temp);
        values[i] = values[i - 1] + temp;
    }
    int num2;
    input(d, &num2);
    LL target = 0;
    for (int i = 1; i <= num2; i++)
    {
        input(lld, &target);
        int result = binarySearch(values, 1, inputnum1, target, inputnum1);
        display("Case #%d: %d\n", i, result);
    }
    return 0;
}