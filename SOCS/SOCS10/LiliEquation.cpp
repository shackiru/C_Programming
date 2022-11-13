#include <stdio.h>

int recursion(int m, int n)
{
    if(m == 0 || n == 0)
    {
        return 1;
    }
    return recursion(m - 1, n - 1) + recursion(m - 1, n) + recursion(m, n - 1);
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d\n", recursion(m, n));
    
    return 0;
}
