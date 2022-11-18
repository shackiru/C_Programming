#include <stdio.h>

int main()
{
    long long int cases;
    scanf("%d", &cases);

    long long int num[cases];
    for(int tc = 0; tc < cases; tc++)
    {
        scanf("%lld", &num[tc]);
    }

    long long int max;
    long long int calc = 0;
    long long int temp = 0;

    scanf("%lld", &max);
    for(int i = cases - 1; i >= 0; i--)
    {   
        for(int j = cases - 1; j >= 0; j--)
        {
            calc = 0;
            if(i + j - 1 < cases)
            {
                for(int k = j; k >= 1; k--)
                {
                    calc = calc + num[i + j - k] * k;
                    if(calc <= max && temp <= calc)
                    {
                        temp = calc;
                    }
                }
            }
        }
    }
    printf("%lld\n", temp);
    return 0;
}