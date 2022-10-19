#include <stdio.h>

int main()
{
    int sum1[10];
    int sum2[10];

    for(int tc = 0; tc < 3; tc++)
    {
        scanf("%d + %d =", &sum1[tc], &sum2[tc]);
    } 

    for(int tc = 0; tc < 3; tc++)
    {
        printf("%d\n", sum1[tc] + sum2[tc]);
    }

    return 0;
}
