#include <stdio.h>
#define ROWS 3
#define COLS 3

int main(void)
{
	int n[ROWS][COLS];
	
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			printf("Array[%d][%d]=", i, j);
			scanf("%d", &n[i][j]);
		}
	}
	
	printf("\n");
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLS; j++)
		{
			printf("%d ", n[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
