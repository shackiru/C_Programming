#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char name[200][30];
char score[200];
char major[200][50];
int index = 0;

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
		printf("Enter Your Name[1-50 Characters]:");
		scanf("%[^\n]", inputName);
		getchar();
	}
	while(strlen(inputName) < 1 || strlen(inputName) > 50);
	
	do
	{
		printf("Enter Your Score [1-100]:");
		scanf("%d", &inputScore);
		getchar();
	}
	while(inputScore < 1 || inputScore > 100);
	
	do
	{
		printf("Enter Your Major[1-50 Characters]:");
		scanf("%[^\n]", inputMajor);
		getchar();
	}
	while(strlen(inputMajor) < 1 || strlen(inputMajor) > 50);
	
	strcpy(name[index], inputName);
	score[index] = inputScore;
	strcpy(major[index], inputMajor);
	index++;
	
}

void mainMenu()
{
	int input = -1;
	
	
	do
	{
		printf("Main Menu\n");
		printf("1. View Data\n");
		printf("2. Add Data\n");
		printf("3. Update Data\n");
		printf("4. Delete Data\n");
		printf("5. Exit\n");
		
		scanf("%d", &input);
		getchar();
			
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
			
			case 5:
			{
				break;
			}
		}
	}
	while(true);
}

void exitProgram()
{
	FILE *fp = fopen("Result.csv", "w");
	
	int i = 0;
	while(i < index)
	{
		fprintf(fp, "%s, %d, %s\n", name[i], score[i], major[i]);
        i++;
	}
    fclose(fp);
    printf("Thank you for using this program\n");
}

int main()
{

    FILE *f = fopen("Score.txt", "r");

    if(f == NULL)
    {
        printf("File Not Found!\n");
    }
    else
    {
        while(!feof(f))
        {
            fscanf(f, "%[^#]#%d#%[^\n]\n", name[index], &score[index], major[index]);
            index++;
        }
    }
    
	mainMenu();
    fclose(f);

    return 0;
}
