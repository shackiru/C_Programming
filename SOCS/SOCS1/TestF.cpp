#include <stdio.h>

int main()
{
	int number[10];
	int plus[10];
	
	for(int i = 0; i < 3; i++)
	{
		scanf("%d + %d =", &number[i], &plus[i]);
	}
	for (int i = 0; i < 3; i++)
	{	
		printf("%d\n", number[i] + plus[i]);
	}
	
	return 0;
}
