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
    if(n == 0)
    {
        return 1;
    }
    return cc3(n - 7) + cc3(n - 5) + cc3(n - 3);
}

int main()
{
    return 0;
}