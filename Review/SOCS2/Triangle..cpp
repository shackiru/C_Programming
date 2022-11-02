#include <stdio.h>

int main()
{
    int inputCase;
    int numOfCase[100];
    int i, k;

    scanf("%d", &inputCase);
    for(int tc = 0; tc < inputCase; tc++)
    {
        scanf("%d", &numOfCase[tc]);
        printf("Case #%d:\n", tc + 1);
        if(numOfCase[tc] % 2 == 0)  
        {
            for(i = 0; i < numOfCase[tc]; i++)
            {
                for(k = numOfCase[tc] - 1; k > i; k--)
                {
                    printf(" ");
                }
                for(k = 0; k <= i; k++)
                {
                    if(k % 2 == 0)
                    {
                        printf("#");
                    }
                    else
                    {
                        printf("*");
                    }
                }
                printf("\n");
            }
        }
        else
        {
            for(i = 0; i < numOfCase[tc]; i++)
            {
                for(k = numOfCase[tc] - 1; k > i; k--)
                {
                    printf(" ");
                }
                for(k = 0; k <= i; k++)
                {
                    if(k % 2 == 0)
                    {
                        printf("*");
                    }
                    else
                    {
                        printf("#");
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}