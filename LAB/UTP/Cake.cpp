#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	char	cakeName[1000][25];
	char	cakeFlavours[1000][25];
	int		cakeID[1000];
	int		cakeQuantities[1000];
	
	int dataIndex = 0;
	int menuInput = 0;
	srand(time(0));
	
	do
	{
		if(dataIndex == 0)
		{
			printf("Nothing Here\n");
		}
		else
		{
			for(int i = 0; i < dataIndex; i++)
			{
				printf("No. %d\n", i + 1);
				printf("ID Cake	        : %d\n", cakeID[i]);
				printf("Cake Name       : %s\n", cakeName[i]);
				printf("Cake Flavours   : %s\n", cakeFlavours[i]);
				printf("Cake Quantities : %d\n", cakeQuantities[i]);
			}
		}
		
		printf("Cake Shop\n");
		printf("1. Add cake\n");
		printf("2. Update cake\n");
		printf("3. Delete cake\n");
		printf("4. Exit\n");
		
		scanf("%d", &menuInput);
		getchar();
		
		switch(menuInput)
		{
			case 1:
				{
					int id;
					id = rand() % 1000;
					
					char name[25];
					do
					{
						printf("Enter your Cake Name : ");
						scanf("%[^\n]", name);
						getchar();				
					}
					while(strlen(name) == 0);
					
					char flavours[25];
					do
					{
						printf("Select your Flavours [Chocolate, Strawberry, Vanilla, Red Velvet] :");	
						scanf("%[^\n]", flavours);
						getchar();
					}
					while(strcmp(flavours, "Chocolate") != 0 
					&& strcmp(flavours, "Strawberry") != 0 
					&& strcmp(flavours, "Vanilla") != 0 
					&& strcmp(flavours, "Red Velvet") != 0);
					
					cakeID[dataIndex] = id;
					strcpy(cakeName[dataIndex], name);
					strcpy(cakeFlavours[dataIndex], flavours);
					
					dataIndex++;

					printf("Success\n");
					printf("\n");
					
					break;
				}
			
		}
				
	}
	while(menuInput != 4);
	
	return 0;
}
