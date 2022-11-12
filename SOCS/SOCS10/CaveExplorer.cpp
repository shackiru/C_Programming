#include <stdio.h>
#include <math.h>

int main()
{
    int cases;
    scanf("%d", &cases);

    int col = pow(2, cases) - 1;
    int x = 1;
    int reset = col - x;

    for(int i = 0; i < cases; i++)
    {
        for(int j = 1; j <= col; j ++)
        {
            if(j % x == 0)
            {
                printf("*");
            }
            else
            {
                if(j <= reset)
                {
                    printf(" ");
                }
            }
        }
        x = x * 2;
        reset = col - x;
        printf("\n");
    }
    return 0;
}
