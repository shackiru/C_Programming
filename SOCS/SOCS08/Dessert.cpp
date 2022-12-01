#include <stdio.h>

int main()
{
	int cases;
	
	scanf("%d", &cases);
	
	long long sum = 1;
	for(int i = 0; i < cases; i++)
	{
		sum = sum * 2;
	}
	printf("%lld\n", sum - 1);
	
	return 0;
}
