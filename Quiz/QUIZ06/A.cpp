#include <stdio.h>

int main()
{
	int n;
	int a, b;
	int num = 0;
	
	scanf("%d %d", &a, &b);
	scanf("%d", &n);
	
	for(int i = 1; i < n; i++)
	{
		num = a + b;
		a = b;
		b = num;
	}
	printf("%d\n", num);
	
	
	return 0;
}
