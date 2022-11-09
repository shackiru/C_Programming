#include <stdio.h>

int coin(int n)
{
    if(n < 0)
    {
        return 0;
    }
    if(n == 0)
    {
        return 1;
    }
    return coin(n - 7) || coin(n - 5) || coin(n - 3);
}

int main()
{
    printf("%d\n", coin(4));
    printf("%d\n", coin(100));

    return 0;
}