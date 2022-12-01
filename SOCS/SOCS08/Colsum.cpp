#include <stdio.h>

int main()
{
	int testCase;
	int amountCase;
	int count[505][505];
	int sum;
	
	scanf("%d", &testCase);
	for(int tc = 0; tc < testCase; tc++)
	{
		scanf("%d", &amountCase);
		sum = 0;
		for(int i = 0; i < amountCase; i++)
		{
			for(int j = 0; j < amountCase; j++)
			{
				scanf("%d", &count[i][j]);	
			}
		}
		printf("Case #%d:", tc + 1);
		for(int i = 0; i < amountCase; i++)
		{
			for(int j = 0; j < amountCase; j++)
			{
				sum = sum + count[j][i];
			}
			printf(" %d", sum);
			sum = 0;
		}
		printf("\n");	
	}
	
	return 0;
}
