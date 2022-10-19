#include <stdio.h>

int main()
{
	unsigned int a, b;
	long long int sum;
	
	scanf("%u %u", &a, &b);
	sum = 0;
	
	for(int i = a; i <= b; i++)
	{
		sum = sum + i;
	}
	printf("%lld\n", sum);
	
	return 0;
}
