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
		for(int i = 0; i < amountCase; i++)
		{
			for(int j = 0; j < amountCase; j++);
			{
				scanf("%d", &count[i][j]);	
			}
		}
		printf("%d", sum);
	}
	
	return 0;
}
