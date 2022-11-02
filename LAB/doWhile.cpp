#include <stdio.h>

int main()
{
	//Infinite Looping => kondisi tidak terpenuhi
	
	// While loop
	
	/*
	int j = 10;
	
	while(j<10)
	{
		printf("something\n");
		j++;
	}
	*/
	
	//Do While Loop
	
	/*
	int x = 10;
	
	do
	{
		printf("something\n");
		x++;
	}
	while(x < 10);
	*/
	
	/*
	int z = 0;
	while(true)
	{
		if(z==10)
		{
			break;
		}
		printf("something\n");
		z++;
	}
	*/
	
	/*
	int input = 0;
	
	do
	{
		printf("1. Menu\n");
		printf("2. Food\n");
		printf("3. Exit\n");
		scanf("%d", &input);
		
		if(input==1)
		{
			printf("Do Something\n");
		}
		else if(input==2)
		{
			printf("Exiting the program....\n");
		}
	}
	while(input!=2);
	
	while(input<1||input>3)
	{
		printf("1. Menu\n");
		printf("2. Food\n");
		printf("3. Exit\n");
		scanf("%d", &input);
		
		if(input==1)
		{
			printf("Do Something\n");
		}
		else if(input==2)
		{
			printf("Exiting the program....\n");
		}
	}
	*/
	
	int menu;
	do
	{
		printf("Menu\n");
		printf("1. Make Triangle\n");
		printf("2. Exit\n");
		
		scanf("%d", &menu);
		getchar();
		
		if(menu==1)
		{
			int n;
			do
			{
				printf("Input N [1-50] : ");
				scanf("%d", &n);
				getchar();
			}
			while(n<1 || n>50);
			
			int a, b=0, c;
			
			for(int i = 0; i < n; i++)
			{
				for(b = 0; b <= i; b++)
				{
					if(i == n - 1 || b == 0 ||b == i)
						{
							printf("%d ", b);
						}
					else
					{
						printf("  ");
					}
				}
				printf("\n");
			}
		
		}
		else if(menu==2)
		{
			printf("Exit...\n");
		}
	}
	while(menu!=2);
	
	return 0;
}
