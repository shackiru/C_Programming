#include <stdio.h>

int cc1(int n)
{
    if(n < 0)
    {
        return 0;
    }
    if(n == 0)
    {
        return 1;
    }
    return cc1(n - 7) || cc1(n - 5) || cc1(n - 3);
}

int min(int a, int b)
{
    return a < b? a : b;
}

int cc2(int n)
{
    if(n < 0)
    {
        return 400000;
    }
    if(n == 0)
    {
        return 0;
    }
    return min (cc2(n - 7), min(cc2(n - 3), cc2(n - 3))) + 1;
}

int cc3(int n)
{
    if(n < 0)
    {
        return 0;
    }
    else if(n == 0)
    {
        return 1;
    }
    else
    {
        return cc3(n - 7) + cc3(n - 5) + cc3(n - 3);
    }
}

int main()
{
    printf("%d\n", cc1(4));
    printf("%d\n", cc2(4));
    printf("%d\n", cc1(100));
    printf("%d\n", cc2(50));
    printf("%d\n", cc3(50));

    return 0;
}