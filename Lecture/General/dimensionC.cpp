#include <stdio.h>

int main()
{
	int M[5][5] = 
	{
		{1, 2},
		{3, 4}
	};		
		  
	int N[3][3] = 
	{
		1, 2, 3, 
		4, 5, 6, 
		7, 8, 9
	};

	printf("%d\n", M[1][0]);	
	printf("%d\n", N[2][0]);	
	
	int input;
	int array[105][105];
	
	scanf("%d", &input);
	for(int i = 0; i < input; i++)
	{
		for(int j = 0; j < input; j++)
		{
			scanf("%d", &array[i][j]);
		}
	}
	
	int total = 0;
	
	for(int i = 0; i < input; i++)
	{
		for(int j = 0; j < input; j++)
		{
			if(i == j)
			{
				total = array[i][j] + 1;
			}
		}
	}
	
	return 0;
}
