#include <stdio.h>

int main()
{
	int input, a[1000], b[1000];
	
	scanf("%d", &input);
		
	for(int i = 0; i < input; i++)
	{
		scanf("%d", &a[i]);
		
	}
	
	for(int i = 0; i < input; i++)
	{
		scanf("%d", &b[a[i]]);
	}
	
	for(int i = 0; i < input; i++)
	{
		printf("%d", b[i]);
		if(input - 1 != i)
		{
			printf(" ");
		}
	}
	printf("\n");
	
	return 0;
}
