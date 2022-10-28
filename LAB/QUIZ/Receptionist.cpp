#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Visitor
{
    char id[7];
    char name[105];
    int age[105];

};

Visitor visitorArr[205];
int size = 0;

void displayAll()
{
    for(int i = 0; i < size; i++)
    {
        printf("%d - %s - %s - %d\n", i + 1, visitorArr[i].id, visitorArr[i].name, visitorArr[i].age);
    }
}

void readFile()
{
    FILE * fp = fopen("visitors.txt", "r");

    if(fp == NULL)
    {
        return;
    }

    while(!feof(fp))
    {
        fscanf(fp, "%[^#]#%[^#]#%d\n", visitorArr[size].id, visitorArr[size].name, &visitorArr[size].age );
        size++;
    }
}

void addData()
{
	char visitorName[35];
	int visitorAge;
	
	do
	{
		printf("Input Name [5 - 30 Characters]: ");
		scanf("%[^\n]", visitorName);
		if(strlen(visitorName) < 5 || strlen(visitorName) > 30)
		{
			printf("Name Must Be Between 5 - 30 Characters!\n");
		}
		getchar();
	}
	while(strlen(visitorName) < 5 || strlen(visitorName) > 30);
	
	do
	{
		printf("Input Age [18 - 50]: ");
		scanf("%d", &visitorAge);
		if(visitorAge < 18 || visitorAge > 50)
		{
			printf("Age Must Be Between 18 - 50 Years Old!\n");
		}
		getchar();
	}
	while(visitorAge < 18 || visitorAge > 50);
	
	char visitorID[10];
	sprintf(visitorID, "%c%c%c%d%d%d", 
	rand() % 26 + 'A', 
	rand() % 26 + 'A', 
	rand() % 26 + 'A',
	rand() % 10,
	rand() % 10,
	rand() % 10);
	
	printf("Visitor Detail: \n");
	printf("Name: %s\n", visitorName);
	printf("Age: %d\n", visitorAge);
	printf("ID: %s\n", visitorID);
}

void viewData()
{

}

void deleteData()
{

}

void saveData()
{
	
}

void mainMenu()
{
	int input;
	
	while(true)
	{
		printf("Main Menu\n");
		printf("1. Add Visitor\n");
		printf("2. View All Visitor\n");
		printf("3. Delete Visitor\n");
		printf("4. Save & Exit\n");
		printf("Input 1 - 4: ");
		
		scanf("%d", &input);
		getchar();
	
		switch(input)
		{
			case 1:
				{
					addData();
					break;
				}
			case 2:
				{
					viewData();
					break;
				}
			case 3:
				{
					deleteData();
					break;	
				}
			case 4:
				{
					saveData();
					break;
				}
			default:
				{
					printf("Invalid Input\n");
				}
		}
	}
}


int main()
{
    srand(time(0));
    readFile();
    displayAll();
    mainMenu();

    return 0;
}
