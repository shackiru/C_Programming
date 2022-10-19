#include <stdio.h>

int main()
{
	int a = 5, b = 7;
	int y = ++a;
	int z = a++;
	
	printf("%d %d\n", y, a);
	printf("%d %d\n", z, a);
	printf("%d %d %d\n", b++, ++b, b++);
	
	
	if (b > 7)
	{
		printf("lebih besar\n");
	}
	else
	{
		printf("lebih kecil\n");
	}
	
	b > 7 ? printf("besar\n") : printf("kecil\n");
	
	return 0;
}
