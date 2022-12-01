#include <stdio.h>

int main()
{
	int input, inputValue;
	int value;
	long long int matrix[100][100] = {0};
	
	scanf("%d", &input);
	
	for(int i = 0; i < input; i++)
	{
		scanf("%d", &inputValue);
		for(int k = 0; k < inputValue; k++)
		{
			for(int j = 0; j < inputValue; j++)
			{
				scanf("%d", &value);
				matrix[k][j] = value;	
			}
		}	
		
		printf("Case #%d:", i + 1);
		
		int sum = 0;
		
		for(int k = 0; k < inputValue; k++)
		{
			for(int j = 0; j < inputValue; j++)
			{
				sum = sum + matrix[j][k];
			}
			printf(" %d", sum);
			sum = 0;
		}
		printf("\n");
	}
	
	
	return 0;
}
