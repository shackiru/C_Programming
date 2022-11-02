#include <stdio.h>

int main()
{
	int input;
	
	scanf("%d", &input);
	
	int arrayA[200000];
	int arrayB[200000] ;
	int max = 0;
	int storage = 0;
	int inputB, inputValue;
	
	for(int i = 0; i < input; i++)
	{
		scanf("%d", &inputB);
		for(int j = 0; j < inputB; j++)
		{
			scanf("%d", &inputValue);
			arrayA[inputValue-1]++;
		}
	
	
		for(int j = 0; j < 200000; j++)
		{
			if(max > arrayA[j])	
			{
				max = max;
			}
			else
			{
				max = arrayA[j];
			}
		}
	
		for(int j = 0; j < 200000; j++)
		{
			if(arrayA[j] == max)
			{
					arrayB[storage] =j+1;
					storage++;
					arrayA[j]=0;
			}
			else
			{
				arrayA[j]=0;				
			}
		}
	
		printf("Case #%d: %d\n", i+1, max);
		for(int j = 0; j < storage; j++)
		{
			if(j != storage - 1)
			{
				printf("%d ", arrayB[j]);
			}
			else
			printf("%d", arrayB[j]);
		}
		puts("");
		storage = 0;
		max = 0;
	}
	
	return 0;
}
