#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char name[200][30];
char score[200];
char major[200][50];

void displayAll()
{
    for(int i = 0; i < 20; i++)
    {
        printf("Data-%d\n", i + 1);
        printf("Name : %s\n", name[i]);
        printf("Score : %d\n", score[i]);
        printf("Major : %s\n\n", major[i]);
    }
}

void addData()
{	
	char inputName[30];
	int inputScore;
	char inputMajor[50];
	
	do
	{
		printf("Enter Your Name[1-30 Characters]:");
		scanf("%[^\n]", inputName);
		getchar();
	}
	while(strlen(inputName) < 1 || strlen(inputName) > 30);
}

void mainMenu()
{
	int input;
	do
	{
		printf("Main Menu!\n");
		printf("1. View Data\n");
		printf("2. Add Data\n");
		printf("3. Update Data\n");
		printf("4. Delete Data\n");
		printf("5. Exit\n");
		
		switch(input)
		{
			case 1:
			{
				displayAll();
				break;
			}
				
			case 2:
			{
				addData();
				break;
			}
				
			case 3:
			{
				break;
			}
				
			case 4:
			{
				break;	
			}
		}
	}
	while(input < 1 || input > 5);
}

int main()
{
    int index = 0;

    FILE *f = fopen("Score.txt", "r");

    if(f == NULL)
    {
        printf("File Not Found!\n");
    }
    else
    {
        printf("File Exist\n");
        while(!feof(f))
        {
            fscanf(f, "%[^#]#%d#%[^\n]\n", name[index], &score[index], major[index]);
            index++;
        }
        displayAll();
    }
	mainMenu();
    fclose(f);

    return 0;
}
