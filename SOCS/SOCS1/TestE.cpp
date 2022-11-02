#include <stdio.h>

int main()
{
	int query;
	int numOne[30];
	int	numTwo[30];
	int result[30];
	
	scanf("%d", &query);
	
	for(int i = 0; i < query; i++)
	{
		scanf("%d %d", &numOne[i], &numTwo[i]);
		result[i] = ((numOne[i] / numTwo[i]) << numTwo[i]);
	}
	
	for(int i = 0; i < query; i++)
	{
		printf("%d\n", result[i]);
	}
	
	return 0;
}
