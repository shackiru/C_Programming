#include <stdio.h>

int main()
{
	int input;
	int matrix;

	scanf("%d", &input);
	
	int array[150] = {};
	
	for(int index = 0; index < input * input; index++)
	{
		scanf("%d", &matrix);
		array[matrix]++;
	}
	
	int matrix2 = 0;
	for(int index = 1; index <= input; index++)
	{
		if(array[index] < input)
		{
			matrix2++;
		}
	}
	
	printf("%d\n", matrix2);
	
	return 0;
}
