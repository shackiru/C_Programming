#include <stdio.h>

int main()
{
	long long int n;
	long long int value;
	long long int num;
	long long int res[100];
	long long int sum = 0;
	
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &value);
		for (int k=0; k<value; k++)
		{
			scanf("%lld", &num);
			sum = sum + num;		
		}	
		res[i] = sum;
		sum = 0;
	}
	
	for (int i = 0; i<n; i++)
	{
		printf("Case #%d: %lld\n", i+1, res[i]);
	}

	return 0;
}
