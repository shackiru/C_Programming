#include <stdio.h>

int main()
{
    int numCase;
    int calc = 0;
    int comp = 0;

    scanf("%d", &numCase);
    int num[numCase];
    for(int i = 0 ; i < numCase; i++)
    {
        scanf("%d", &num[i]);
    }

    int max;
    scanf("%d", &max);
    for(int j = numCase - 1; j >= 0; j--)
    {
        for(int k = numCase - 1; k >= 0; k--)
        {
            calc = 0;
            if(j + k - 1 < numCase)
            {
                for(int x = k; x >= 1; x--)
                {
                    calc = calc + num[j + k - x] * x;
                    if(calc <= max && comp <= calc)
                    {
                        comp = calc;
                    } 
                }
            }
        }
    }
    printf("%d\n", comp);
    return 0;
}