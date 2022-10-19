#include <stdio.h>

int main()
{
	long long int num;
	
	scanf("%d", &num);
	printf("%d = %d + %d\n", num, (num - 1) / 2, (num + 1) / 2);
	
	return 0;
}
