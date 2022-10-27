#include <stdio.h>

int main()
{
	int size;
	int matrix[105][105];
	int transpose[105][105];
		
	scanf("%d", &size);
	for(int tc = 0; tc < size; tc++)
	{
		for(int i = 0; i < size; i++)
		{
			scanf("%d", &matrix[tc][i]);
			transpose[i][tc] = matrix[tc][i];
		}
	}
	
	for(int tc = 0; tc < size; tc++)
	{
		for(int i = 0; i < size; i++)
		{
			if(i != 0)
			{
				printf(" ");
			}
			printf("%d", transpose[tc][i]);
		}
		printf("\n");
	}
	
	return 0;
}
