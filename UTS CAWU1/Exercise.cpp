#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	char productID[1000][11];
	char productName[1000][25];
	char productType[1000][25];
	int productQuantities[1000];
	int productPrice[1000];
	
	int menu = 0;
	int index = 0;
	
	do
	{
		if(index == 0)
		{
			printf("Nothing Here\n");
		}
		else
		{
			for(int i = 0; i < index; i++)
			{
				printf("\nProduct ID : %s\n", productID[i]);
				printf("What is this product? it's %s\n", productName[i]);
				printf("What is the type of this product? it's %s\n", productType[i]);
				printf("How product do I want? I want %d\n", productQuantities[i]);
				printf("How much cost of this product? %d\n", productPrice[i]);
			}
		}
		printf("Welcome to NONAME STORE\n");
		printf("Please Choose our menu:\n");
		printf("1. Add Product\n");
		printf("2. Update Product\n");
		printf("3. Delete Product\n");
		printf("4. Exit\n");
		
		do
		{
			printf("Input your menu:");
			scanf("%d", &menu);
			getchar();
		}
		while(menu < 1 || menu > 4);
			
		
		switch(menu)
			{
				case 1:
					{
						char id[100] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
						for(int i = 0; i < 11; i++)
						{
							productID[index][i] = id[rand() % 62];
						}
						
						char name[25];
						do
						{
							printf("Enter your product right here :");
							scanf("%[^\n]", name);
							getchar();
						}
						while(strlen(name) == 0);
						
						char type[25];
						do
						{
							printf("Enter the type of product [Dog, Cat, Human]:");
							scanf("%[^\n]", &type);
							getchar();
						}
						while(strcmp(type, "Dog") != 0
						&& strcmp(type, "Cat") != 0
						&& strcmp(type, "Human") != 0);
						
						strcpy(productName[index], name);
						strcpy(productType[index], type);
						
						index++;
						
						printf("Add data successful\n");
						
						break;
					}
					
				case 2:
					{
						
						break;
					}
					
				case 3:
					{
						
						break;
					}
			}
	}
	while(menu != 4);
	
	return 0;
}
