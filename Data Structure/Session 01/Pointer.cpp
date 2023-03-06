#include <stdio.h>

int main()
{
	int a = 10;
	int *p = &a;
	
	printf("%d\n", *p);
	
	a = 17;
	*p = 20;
	
	printf("%d\n", a);
	
	return 0;
}
