#include <stdio.h>

int main()
{
	long long int input, inputValue;
	
	scanf("%lld", &input);
	
	for(int i = 0; i < input; i++)
	{
		scanf("%lld", &inputValue);
		
		long long int test[inputValue];
		long long int average[inputValue];
		long long int sum = 0;
		
		for(int j = 0; j < inputValue; j++)
		{
			scanf("%lld", &test[j]);
		}
		
		for(int k = 0; k < inputValue; k++)
		{
			scanf("%lld", &average[k]);
		}
		
		for(int x = 0; x < inputValue; x++)
		{
			if(average[x] > test[x])
			{
				sum = sum + 1;
			}
		}
		
		printf("Case #%lld: %lld\n", i+1, sum);
			
	}
	
	return 0;
}
