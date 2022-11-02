#include <stdio.h>

struct Game
{
    int id;
    char title[55];
    char description[105];
    int quantity;
    double price;
}games[105];

int numberOfData;

void displayAllGames()
{
	for(int i = 0; i < numberOfData; i++)
	{
		printf("Data %d\n", i + 1);
		printf("ID: %d\n",games[i].id);
		printf("Title: %d\n",games[i].title);
		printf("Description: %d\n",games[i].description);
		printf("Quantity: %d\n",games[i].quantity);
		printf("Price: %0.3lf\n",games[i].price);
	}
}

void addGame()
{
    printf("ID: ");
    scanf("%d", &games[numberOfData].id);
    getchar();

    printf("Title: ");
    scanf("%[^\n]", games[numberOfData].title);
    getchar();
    
    printf("Description: ");
    scanf("%[^\n]", games[numberOfData].description);
    getchar();

    printf("Quantity: ");
    scanf("%d", &games[numberOfData].quantity);
    getchar();

    printf("Price: ");
    scanf("%lf", &games[numberOfData].price);

    numberOfData++;
    printf("Game Added to Catalog!\n");
}

//void clearScreen()
//{
//	for(int x = 0; x < 20; x++)
//	{
//		printf("\n");
//	}
//}

int main()
{
    int menu = 0;
    int numOfData = 0;

    do
    {
//    	clearScreen();
        printf("Game Catalog\n");
        printf("==================\n");
        printf("1. Add Game\n");
        printf("2. Display All Games\n");
        printf("3. Exit\n");
        printf("Choice: ");

        scanf("%d", &menu);
        getchar();

        if(menu == 1)
        {
            addGame();
        }
        else if(menu == 2)
        {
            displayAllGames();
        }
    }
    while(true);

    return 0;
}
