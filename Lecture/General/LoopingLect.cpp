#include <stdio.h>

int main()
{
	/*
		looping
		for
		do-while
		while
		
		for([initiate]; [condition]; [statement])
		while([condition])
		
		shorthand operator (untuk menyingkat sebuah operator)
		example : 
				a++; post-increment (a = a + 1)
				++a; pre-increment  (a = a + 1)
				  
				a--; post-decrement (a = a - 1)
				--a; pre-increment  (a = a - 1)
				
				a+=2; -> a = a + 2;	
				a-=2; -> a = a - 2;	
				a*=2; -> a = a * 2;	
				a/=2; -> a = a / 2;	
				a%=2; -> a = a % 2;
				
				bitwise
				a|=2; -> a = a | 2;	
				a&=2; -> a = a & 2;	
			
	*/
	int a;
	int b = 10;
	b = b + 1;
	
	
	//for example
	for(int i = 1; i < 10/2; i++)
	{
//		printf("Loop for %d\n", i + 1);
		printf("Loop for %d\n", (i * 2) - 1);
	}
	
	for(int i = 0; i < 10; i++)
	{
		printf("Loop for %d\n", i + 1);
	}
	
	int j = 0;
	
	//while example
	while(j < 10)
	{
		printf("Loop while %d\n", j);	
		j++;
	}
	
	//do-while example
	int f = 0;
	do
	{
		printf("Loop do while %d\n", f);
		f++;
	}
	while(f < 10);
	
	return 0;
}
