#include <stdio.h>

int main()
{
	long long int inputA, inputValue;
	long long int contA, contB, dump;
	int value[100000];
	
	scanf("%lld", &inputA);
	for(int i = 0; i < inputA; i++)
	{
		scanf("%lld", &inputValue);
		
		contA = -1000000;
		contB = -1000000;
		for(int j = 0; j < inputValue; j++)
		{
			scanf("%lld", &value[j]);
			if(contA <= value[j])
			{
				contA = value[j]; 
				dump = j;
			}
		}
		for(int k = 0; k < inputValue; k++)
		{
			if(contB < value[k] && k != dump)
			{
				contB = value[k];
			}				
		}
		printf("Case #%d: %lld\n", i + 1, (contA + contB));
	}
	
	return 0;
}
		
