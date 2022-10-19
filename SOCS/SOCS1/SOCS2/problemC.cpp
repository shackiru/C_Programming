#include <stdio.h>

int main()
{
	int a, b, c, d;
	int total = 0;
	
	scanf("%d", &a);
	int sum[a];
	int la[100];
	
	for(int i = 0; i < a; i++)
	{
		scanf("%d", &sum[i]);
	}
	
	scanf("%d", &b);
	
	for(int i = 0; i < b; i++)
	{
		scanf("%d %d", &c, &d);
		
		for(int j = c; j <= d; j++)
		{
			total = total + sum[j - 1];
		}
		la[i] = total;
		total = 0;
	}
	
	for(int i = 0; i < b; i++)
	{
		printf("Case #%d: %d\n", i + 1, la[i]);
	}
	return 0;
}
