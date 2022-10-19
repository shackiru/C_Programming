#include <stdio.h>

int main()
{
    int n;
    int modulo;

    scanf("%d", &n);
    scanf("%d", &modulo);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < n; i++)
    {
        if(i % modulo == 0)
        {
            for(int j = 0; j < n; j++)
            {
                printf("#");
            }
            printf("\n");
        }
        else
        {
            for(int j = 0; j < n; j++)
            {
                printf(".");
            }
            printf("\n");
        }
    }
    return 0;
}