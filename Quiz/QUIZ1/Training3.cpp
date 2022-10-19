#include <stdio.h>

int main()
{
	int a;
	int b;
	int c;
	int d;
	
	int x, y, z, h;
	int sumA = 0;
	int sumB = 0;
	int sumC = 0;
	int sumD = 0;
	
	float result[10];
	
	for(int i = 0; i < 3; i++)
	{
		scanf("%d %d %d %d", &a, &b ,&c, &d);
		
		x = (a*2);
		sumA += x;
		
		y = (b*2);
		sumB += y;
		
		z = (c*2);
		sumC += z;
		
		h = (d);
		sumD += h;
		
		result[i] = sumA + sumB + sumC + sumD;
		
		sumA = NULL;
		sumB = NULL;
		sumC = NULL;
		sumD = NULL;
	}
	for(int i = 0; i < 3; i++)
	{
		printf("%.2f\n", result[i]);
	}
	
	return 0;
}
