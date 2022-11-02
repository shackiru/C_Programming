#include <stdio.h>

int main()
{
    int sum1, sum2;
    int min1, min2;

    int resA;
    int resB;

    scanf("%d %d %d %d", &sum1, &sum2, &min1, &min2);

    resA = sum1 * sum2;
    resB = min1 - min2;

    if(resA == resB)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    } 

    return 0;
}