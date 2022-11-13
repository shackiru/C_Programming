#include <stdio.h>

int abs(int a)
{
	if(a < 0)
	{
		return -a;
	}
	return a;
}

int main()
{
    long long int num[105] = {};
    int cases, amountCases;

    scanf("%d", &cases);
    for(int tc = 0; tc < cases; tc++)
    {
        int min = 1000000;
        scanf("%d", &amountCases);
        num[0] = 0;
        for(int i = 1; i <= amountCases; i++)
        {
            scanf("%lld", &num[i]);
        }
        for(int j = 1; j <= amountCases; j++)
        {
            for(int k = j; k <= amountCases; k++)
            {
                if(j == k)
                {
                    continue;
                }
                if(min > abs(num[j] - num[k]))
                {
                    min = abs(num[j] - num[k]);
                }
            }
        }
        printf("Case #%d: %lld\n", tc + 1, min);
    }
    return 0;
}
