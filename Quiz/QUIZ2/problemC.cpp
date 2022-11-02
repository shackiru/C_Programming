#include <stdio.h>

int main()
{	
	int n, k;
	
	scanf("%d", &n);
	scanf("%d", &k);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			printf("#");
		}
		printf("\n");
	}
	printf("\n");
	
	//persegi 2
	for(int i = 1; i <= n; i++)
	{
		if(i % k == 0)
		{
			for(int k = 1; k <= n; k++)
			{
				printf("#");
			}
			printf("\n");
		}
		else
		{
			for(int k = 1; k <= n; k++)
			{
				printf(".");
			}
			printf("\n");	
		}
	}
	printf("\n");
	
	//persegi 3
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j%k!=0)
			{
				printf(".");	
			}
			else
			{
				printf("#");
			}
		}
			printf("\n");
	}	
	
	return 0;
}
