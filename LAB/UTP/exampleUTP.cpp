#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	/* Data Kue */
	char cakeNames[1000][25];
	char cakeFlavours[1000][25] ;
	int cakeQuantities[1000];
	
	int dataIndex = 0; //total data
	int menuInput = 0;
	
	do
	{
		if(dataIndex == 0)
		{
			printf("No cake found!\n");
		}
		else // show entire cakes
		{
			for(int index = 0; index < dataIndex; index++)
			{
				printf("Number %d\n", index + 1);
				printf("Cake Name : %s\n", cakeNames[index]);
				printf("Cake Flavour : %s\n", cakeFlavours[index]);
				printf("Cake Quantity : %d\n", cakeQuantities[index]);
				printf("\n");
			}	
		}
		
		printf("\n ### Welcome to Cake Cake Shop ###\n");
		printf("===================================\n");
		printf("1. Add Cake\n");
		printf("2. Update Cake\n");
		printf("3. Delete Cake\n");
		printf("4. Exit\n");
		printf("Choice :");
		scanf("%d", &menuInput);
		getchar();
		
		switch(menuInput)
		{
			case 1: 
			{//add Cake
				char name[25];
				char subStr[25] = "Cake";
				
				int nameLen = 0;
				int subStrLen = strlen(subStr);
				
				bool endsWith = false;
				
				do
				{
					printf("Cake Name[Not Empty & ends with 'Cake']: ");
					scanf("%[^\n]", name);
					getchar();
					
					nameLen = strlen(name);
					
						for(int index = 0; index < subStrLen; index++)
						{
							if(name[nameLen - subStrLen + index] != subStr[index])
							{
								endsWith = false;
								break;
							}
							endsWith = true;
						}
				}
				while(strlen(name) == 0|| endsWith == false);
				
				char flavour[25];
				do
				{
					printf("Cake Name['Chocolate' | 'Red Velvet']: ");
					scanf("%[^\n]", flavour);
					getchar();
				}
				while(strcmp(flavour, "Chocolate") != 0 &&
				strcmp(flavour, "Red Velvet") != 0);
				
				int quantity = 0;
				do
				{
					printf("Cake Quantity[1 - 10]: ");
					scanf("%d", &quantity);
					getchar();
				}
				while(quantity < 1 || quantity > 10);
				
				strcpy(cakeNames[dataIndex], name);
				strcpy(cakeFlavours[dataIndex], flavour);
				cakeQuantities[dataIndex] = quantity;
				
				dataIndex++;
				
				printf("Cake added successfully!\n");
				printf("\n");
				
				break;
			}
			
				
			case 2:
			{
				int index;
				char name[25];
				char subStr[25] = "Cake";
				
				int nameLen = 0;
				int subStrLen = strlen(subStr);
				
				bool endsWith = false;

			do
			{
				scanf("%d", &index);
			} while (index > dataIndex);
			
				do
				{
					printf("Cake Name[Not Empty & ends with 'Cake']: ");
					scanf("%[^\n]", name);
					getchar();
					
					nameLen = strlen(name);
					if(nameLen >= subStrLen)
					{
						for(int index = 0; index < subStrLen; index++)
						{
							if(name[nameLen - subStrLen + index] != subStr[index])
							{
								endsWith = false;
								break;
							}
							endsWith = true;
						}
					}
				}
				while(strlen(name) == 0|| endsWith == false);
				
				char flavour[25];
				do
				{
					printf("Cake Name['Chocolate' | 'Red Velvet']: ");
					scanf("%[^\n]", flavour);
					getchar();
				}
				while(strcmp(flavour, "Chocolate") != 0 &&
				strcmp(flavour, "Red Velvet") != 0);
				
				int quantity = 0;
				do 	
				{
					printf("Cake Quantity[1 - 10]: ");
					scanf("%d", &quantity);
					getchar();
				}
				while(quantity < 1 || quantity > 10);
				
				strcpy(cakeNames[index - 1], name);
				strcpy(cakeFlavours[index - 1], flavour);
				cakeQuantities[index - 1] = quantity;	
				
				printf("Cake added successfully!\n");
				printf("\n");
				
				break;
				
			} //update Cake
				
			case 3: // delete Cake
				break;
				
		}
	}
	while(menuInput != 4);
	
	return 0;
}
