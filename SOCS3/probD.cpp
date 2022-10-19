#include <stdio.h>

int main()
{
	long long int a[1000];
	long long int sum = 0;
	int input, x;
	int z = 0;
	
	scanf("%d", &input);
	
	for(int i = 0; i < input; i++)
	{
		scanf("%d", &x);
		int y[x];
		sum = 0;
		z = 0;
		for(int j = 0; j < x; j++)
		{
			scanf("%d", &y[j]);
			sum = sum + y[j];
		}
		for(int k = 0; k < x; k++)
		{
			if(y[k] > sum)
			{
				z++;
			}
			else
			{
				continue;
			}
		}
		printf("Case #%d: %lld\n", i + 1, sum);
		printf("%d\n", z);
	}
	
	return 0;
}
