#include<stdio.h>

int main()
{
	int array[15];
	
	for(int i = 1; i<=10; i++)
	{
		array[i] = 0;
	}
	
	int input;
	int inputValue;
	
	scanf("%d", &input);
	
	for(int i = 0; i < input; i++)
	{
		scanf("%d", &inputValue);
		array[inputValue]++;
	}
	
	for (int i = 1; i <= 10; i++)
	{
		if(array[i] > 0)
		{
			printf("%d : %d\n", i, array[i]);
		}
	}
	
	return 0;
}
