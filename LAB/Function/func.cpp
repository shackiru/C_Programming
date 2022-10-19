#include <stdio.h>
#include <string.h>

void printMainMenu()
{
    printf("Main Menu\n");
    printf("1. Add Data\n");
    printf("2. Update Data\n");
    printf("3. Delete Data\n");
    printf("4. Exit\n");
    printf("Input [1-4]: ");
}

void addDataMenu(char nameArray[200][25], int *seat)
{
    char name[25];
    do
    {
        printf("Input Name [5-20 Characters]:");
        scanf("%[^\n]", name);
        getchar();
    } 
    while (strlen(name) < 5 || strlen(name) > 20);
    
    char code;
    int number;
    do
    {
        printf("Enter Seat [1-26 | A-F]:");
        scanf("%d%c", &number, &code);
        getchar();
    }
    while(number < 1 || number > 26 || code < 'A' || code > 'F');

    strcpy(nameArray[0], name);
    *seat = number;

    printf("Passed\n");
    int input = -1;
    return;
}

int main()
{
    char name[200][25];
    int seat = -1;
    int input = -1;

    do
    {
        printMainMenu();
        scanf("%d", &input);
        getchar();

        switch(input)
        {
            case 1:
            {
                addDataMenu(name, &seat);
                printf("%s %d\n", name[0], seat);
                break;
            }
        }
    } while (input != 4);
    return 0;
}
