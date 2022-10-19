#include <stdio.h>

int main()
{
	int a, y;
	
	scanf("%d %d", &a, &y);
	
	for(int i = a; i < (a + y); i++)
	{
		printf("%d\n", i);
	}
	return 0;
}
