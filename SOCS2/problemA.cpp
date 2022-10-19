#include <stdio.h>

int main()
{
	long long int a, b, c, d;
	long long int resultA, resultC;
	
	scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	
	resultA = a*b;
	resultC = c-d;
	
	
	if(resultA == resultC)
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}

	
	return 0;
}
