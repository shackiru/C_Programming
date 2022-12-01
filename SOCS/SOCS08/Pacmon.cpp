#include <stdio.h>

int sum;
int Game(char container[105][105], int up, int down, int col, int row)
{
	if(container[up][down] == '#' || up < 0 || down < 0 || up >= col || down >= row)
	{
		return 0;
	}
	if(container[up][down] == '*')
	{
		sum++;	
	}
	container[up][down] = '#';
	return 1 + 
	Game(container, up + 1, down, col, row) + 
	Game(container, up - 1, down, col, row) + 
	Game(container, up, down + 1, col, row) +
	Game(container, up, down - 1, col, row);
}

int main()
{
	int testCase;
	int col, row;
	char container[105][105];
	
	scanf("%d", &testCase);
	for(int tc = 0; tc < testCase; tc++)
	{
		scanf("%d %d", &col, &row);
		for(int i = 0; i < col; i++)
		{
			scanf("%s", container[i]);
		}
		
		sum = 0;
		
		for(int j = 0; j < col; j++)
		{
			for(int k = 0;  k < row; k++)
			{
				if(container[j][k] == 'P')
				{
					Game(container, j, k, col, row);
				}
			}
		}
		printf("Case #%d: ", tc +1);
		printf("%d\n", sum);
	}
}
