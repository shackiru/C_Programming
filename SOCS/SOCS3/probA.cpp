#include <stdio.h>

int main()
{
	int col, row, n, col2, row2, c;
		
	scanf("%d %d", &row, &col);
	
	int array[row][col];
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			//printf("%d", i , j);
			scanf("%d", &array[i][j]);
		}
	}
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &col2, &row2, &c);
		array[col2 - 1][row2 - 1] = c;
	}
	
	for(int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			if(j != col - 1)
			{
				printf("%d ", array[i][j]);
			}
			else
			{
				printf("%d", array[i][j]);
			}
		}
		printf("\n");
	}
	
	
	return 0;
}
