#include <stdio.h>

int main()
{
	int forLoop;
	int total = 0;
	int nilai[100];
	int a, b, c, d, e;
	
	scanf("%d", &forLoop);
	for (int i = 0; i < forLoop; i++)
	{
		scanf("%d", &nilai[i]);
			total = total + nilai[i];
	}
	
	printf("%d", total);
	
	return 0;
}
