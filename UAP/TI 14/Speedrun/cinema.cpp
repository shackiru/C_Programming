#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int size = 0;
struct Cinema
{
    char movID[105];
    char movName[105];
    int startHr;
    int startMnt;
    int endHr;
    int endMnt;
    int duration;
    int studio;
}data[105];
void readFile()
{
    FILE *f = fopen("cinema.csv", "r");

    if(f == NULL)
    {
        printf("File not found!\n");
    }
    else
    {
        while(!feof(f))
        {
            fscanf(f, "%[^,],%[^,],%d:%d,%d:%d,%d",
            data[size].movID,
            data[size].movName,
            &data[size].startHr,
            &data[size].startMnt,
            &data[size].endHr,
            &data[size].endMnt,
            &data[size].studio);

            data[size].duration = (data[size].endHr - data[size].startHr) * 60 + (data[size].endMnt - data[size].startMnt);
            size++;
        }
    }
    fclose(f);
}

void add()
{
    char name[50];
    do
    {
        printf("Enter movie name [1 - 50 Characters]: ");
        scanf("%[^\n]", name);
        getchar();
        if(strlen(name) < 1 || strlen(name) > 20)
        {
            printf("Name must be between 1 - 20 characters!\n");
        }
    } while (strlen(name) < 1 || strlen(name) > 20);
    
    int strHr;
    int strMnt;
    do
    {
        printf("Enter start time [HH:MM]: ");
        scanf("%d:%d", &strHr, &strMnt);
        getchar();
        if(strHr < 0 || strHr > 23 || strMnt < 0 || strMnt > 59)
        {
            printf("Invalid time format!\n");
        }
    } while (strHr < 0 || strHr > 23 || strMnt < 0 || strMnt > 59);

    int endHr;
    int endMnt;
    do
    {
        printf("Enter end time [HH:MM]: ");
        scanf("%d:%d", &endHr, &endMnt);
        getchar();
        if(endHr < 0 || endHr > 23 || endMnt < 0 || endMnt > 59)
        {
            printf("Invalid time format!\n");
        }
    } while (endHr < 0 || endHr > 23 || endMnt < 0 || endMnt > 59);

    int duration = (endHr - strHr) * 60 + (endMnt - strMnt);

    int addStd;
    do
    {
        printf("Enter movie studio [1-10]: ");
        scanf("%d", &addStd);
        getchar();
        if(addStd < 1 || addStd > 10)
        {
            printf("Studio must be between 1 - 10!\n");
        }
    } while (addStd < 1 || addStd > 10);

    char id[50];
    sprintf(id, "MV%d%d%d", rand() % 10, rand() % 10, rand() % 10);

    strcpy(data[size].movID, id);
    strcpy(data[size].movName, name);
    data[size].startHr = strHr;
    data[size].startMnt = strMnt;
    data[size].endHr = endHr;
    data[size].endMnt = endMnt;
    data[size].duration = duration;
    data[size].studio= addStd;

    size++;
    printf("Data Add Successfully!\n");
    printf("Press ENTER to continue...");
    getchar();
    
}

void swap(Cinema *a, Cinema*b)
{
    Cinema temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low, int high)
{
    char pivot[10];
    strcpy(pivot, data[size].movID);

    int i = low - 1;
    for(int j = low; j < high; j++)
    {
        if(strcmp(data[j].movID, pivot) < 0)
        {
            i++;
            swap(&data[j], &data[i]);
        }
    }
    swap(&data[i + 1], &data[high]);
    return i + 1;
}

void quickSort(int low, int high)
{
    if(low < high)
    {
        int pivot = (partition(low, high));
        quickSort(low - 1, pivot);
        quickSort(pivot, high + 1);
    }
}

void displayData()
{
    quickSort(0, size - 1);
    for(int i = 0; i < size; i++)
    {
        printf("No.%d\n", i + 1);
        printf("ID: %s", data[i].movID);
        printf("Name: %s", data[i].movName);
        printf("Start Hour: %02d:%02d", data[i].startHr, data[i].startMnt);
        printf("End Time: %02d:%02d", data[i].endHr, data[i].endMnt);
        printf("Duration: %d Minutes", data[i].duration);
        printf("Studio: %d", data[i].studio);
    }
}

void mainMenu()
{
    printf("Hi there!\n");
    printf("1. View All Movie\n");
    printf("2. Add New Movie");
    printf("Choose: ");
    
    int input;
    scanf("%d", &input);
    fflush(stdin);

    switch(input)
    {
        case 1:
        {
            displayData();
            break;
        }
        case 2:
        {
            add();
            break;
        }
        default:
        {
            printf("Invalid input format!\n");
        }
    }
}

int main()
{
    readFile();
    mainMenu();

    return 0;
}