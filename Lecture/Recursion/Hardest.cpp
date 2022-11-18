#include <stdio.h>

int arr[4000005], n;
int long long m, c[4000005];

long long f(int a, int k)
{
    
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", arr[i]);
    }

    long long sum = 0;
    for(int j = n - 1; j >= 0; j--)
    {
        sum = sum + arr[j];
        c[j] = sum;
    }
    scanf("%lld", &m);

    return 0;
}