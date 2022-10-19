#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char itemName[1000][25];
    char itemType[1000][25];
    int itemPrice[1000];

    int dataIndex = 0;
    int menuInput = 0;

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
                printf("Number     :%d \n", i + 1);
                printf("Item Name  :%s \n", itemName[i]);
                printf("Item Type  :%s \n", itemType[i]);
                printf("Item Price :%d \n", itemPrice[i]);
                printf("\n");
            }
        }
        printf(" _ \n");
        printf("| |\n");
        printf("| |      ___   _ _ _  ___  ___  ____      \n");
        printf("| |     / _ \\ | | | |/___)/ _ \\|  _ \\  \n");
        printf("| |____| |_| || | | |___ | |_| | | | |    \n");
        printf("|_______)___/  \\____(___/ \\___/|_| |_|  \n");
        printf("\n");
        
        printf("==============\n");
        printf("1. Create Product\n");
        printf("2. Update Product\n");
        printf("3. Delete Product\n");
        printf("4. Exit\n");
        printf("Choice : ");
        
        scanf("%d", &menuInput);
        getchar();
        
        switch(menuInput)
        	case 1:
        	{	
       			char name[25] = {0};
        		do
        		{
        			printf("Enter Product Name [Product Name cannot be empty] :");
        			scanf("%[^\n]", name);
        			getchar();
				}
				while(strlen(name) == 0);
				
				char type[25] = {0};
				do
				{
					printf("Enter the Type of the Product [Choose : Food, Beverage, Cosmetic, or Others] :");
					scanf("%s", type);
				}
				while(strcmp(type, "Food") != 0 
				&& strcmp(type,"Beverage") != 0 
				&& strcmp(type, "Cosmetic") != 0 
				&& strcmp(type, "Others") != 0);
				
				int price = 0;
				
				do
				{
					printf("Enter Your Range Price :");
					scanf("%d", &price);
				}
				while(price <= 0);
			
				strcpy(itemName[dataIndex], name);
				strcpy(itemType[dataIndex], type);
				itemPrice[dataIndex] = price;
					
				dataIndex++;
				
				printf("\nCake added successfully!\n");
				printf("\n");
				
				break;
			}
			
    }
	while(menuInput != 4);
    
    



    return 0;
}
