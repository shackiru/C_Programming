#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	char cakeID[1000][11];
    char cakeName[1000][25];
    char cakeFlavours[1000][25];
    int cakeQuantities[1000];
    int cakePrice [1000];

    int menuInput = 0;
    int dataIndex = 0;

    do
    {
        if(dataIndex == 0)
        {
            printf("Nothing here\n");
        }
        else
        {
            printf("+===================================================+\n");
            printf("|Number|ID|Cake Name|Flavour|Quantities|\n");
            for(int i = 0; i < dataIndex; i++)
            {
                printf("|%d|%s|%s|%s|%d |\n", i + 1, cakeID[i], cakeName[i], cakeFlavours[i], cakeQuantities[i]);
            }
            printf("+===================================================+\n");
        }
        printf("CAKE SHOP\n");
        printf("Welcome To Cake Shop, Choose the menu\n");
        printf("1. Add Cake\n");
        printf("2. Update Cake\n");
        printf("3. Delete Cake\n");
        printf("4. Exit\n");

        printf("Choose your menu : ");
        scanf("%d", &menuInput);
        getchar();

        switch(menuInput)
        {
            case 1:
            {
                char id[100] = "abcdefghijklmnopqrstuvwxyzQWERTYUIOPASDFGHJKLZXCVBNM1234567890";
                for(int i = 0; i < 11; i++)
                {
                    cakeID[dataIndex][i] = id[rand() % 62];
                }

                char name[25];
                do
                {
                    printf("Enter Your Cake Name:");
                    scanf("%[^\n]", name);
                    getchar();
                } while (strlen(name) == 0);
                
                char flavours[25];
                do
                {
                	printf("Choose your flavour  [Chocolate, Vanilla, Red Velvet, Taro] :");
                    scanf("%[^\n]", flavours);
                    getchar();
				}while(strcmp(flavours, "Chocolate") != 0 
                && strcmp(flavours, "Vanilla") != 0
                && strcmp(flavours, "Red Velvet") != 0
                && strcmp(flavours, "Taro") != 0);

				int quantity;
				do
				{
					printf("Enter Your Quantities [1-10] : ");
					scanf("%d", &quantity);
					getchar();
				}while(quantity < 1 || quantity > 10);

                int price;
                do
                {
                    printf("Enter Your Cake Price :");
                    scanf("%d", &price);
                    getchar();
                } while (price < 9999);
                

                strcpy(cakeName[dataIndex], name);
                strcpy(cakeFlavours[dataIndex], flavours);
                cakeQuantities[dataIndex] = quantity;
                cakePrice[dataIndex] = price;
                
                dataIndex++;

                printf("Add Data Success\n");

                break;
            }

            case 2 :
            {

                break;
            }
        }
    } while (menuInput != 4);
    

    return 0;
}
