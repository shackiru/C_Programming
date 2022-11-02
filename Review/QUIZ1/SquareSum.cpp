#include <stdio.h>

int main()
{
	int a[10];
	int b[10];
	int c[10];
	int d[10];
	
	float result[10];
	
	for(int i = 0; i < 3; i++)
	{
		scanf("%d %1d %d %d", &a[i], &b[i], &c[i], &d[i]);
		result[i] = 2 * ((a[i]) + (b[i]) + (c[i])) + (1*d[i]); 
	}
	for(int i = 0; i < 3; i++)
	{
		printf("%.2f\n", result[i]);
	}
	
	return 0;
}