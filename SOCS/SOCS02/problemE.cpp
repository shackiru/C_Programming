 	#include <stdio.h>

int main()
{
	int a, b; 
	float c, d, e; 
	int total = 0, avg = 0;
	
	
	scanf("%d", &a);
	scanf("%f %f %f", &c, &d, &e);
	
	for(int i = 0; i < a; i++)
	{
		scanf("%d", &b);
		total = total + b;
	}
	avg = (total + c + d + e)/(a+3);
	
	if(c >= avg)
	{
		printf("Jojo lolos\n");
	}
	else
	{
		printf("Jojo tidak lolos\n");
	}
	
	if(d >= avg)
	{
		printf("Lili lolos\n");
	}
	else
	{
		printf("Lili tidak lolos\n");
	}
	
	if(e >= avg)
	{
		printf("Bibi lolos\n");
	}
	else
	{
		printf("Bibi tidak lolos\n");
	}
	
	return 0;
}
