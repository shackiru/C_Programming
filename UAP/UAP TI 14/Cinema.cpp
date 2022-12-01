#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int size = 0;

struct Cinema
{
    char id[105];
    char movieName[105];
    int startHour;
    int endHour;
    int startMinute;
    int endMinute;  
    int duration;
    int studio;  
}data[105];

void readFile()
{
    FILE *f = fopen("cinema.csv", "r");
    
    if(f == NULL)
    {
        printf("File Not Found!\n");
    }
    else
    {
        while(!feof(f))
        {
            fscanf(f,"%[^,],%[^,],%d:%d,%d:%d,%d", 
            data[size].id,
            data[size].movieName,
            &data[size].startHour,
            &data[size].startMinute,
            &data[size].endHour,
            &data[size].endMinute,
            //&data[size].duration,
            &data[size].studio);
            fgetc(f);
            
            data[size].duration = (data[size].endHour - data[size].startHour) * 60 
    		+ (data[size].endMinute-data[size].startMinute);
    		
            size++;
        }
    }
    fclose(f);
}

void displayAll()
{
    if(size == 0)
    {
        printf("Oops. No Movie Available!\n");
        printf("Press Enter To Continue...");
        getchar();
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            printf("No.%d\n", i + 1);
            printf("Movie ID: %s\n", data[i].id);
            printf("Movie Name: %s\n", data[i].movieName);
            printf("Start Time: %02d:%02d\n", data[i].startHour, data[i].startMinute);
            printf("End Time: %02d:%02d\n", data[i].endHour, data[i].endMinute);
            printf("Duration: %d Minutes\n", data[i].duration);
            printf("Studio: %d\n", data[i].studio);
        }
    }
}

void addData()
{
    char name[50];
    do
    {
        printf("Enter Movie Name [1-20 Characters]: ");
        scanf("%[^\n]", name);
        getchar();
        if(strlen(name) > 20 || strlen(name) < 1)
        {
            printf("Movie Name Must Be Between 1 - 20 Characters!\n");
        }
    }
    while (strlen(name) > 20 || strlen(name) < 1);

    int startHourAdd;
    int startMinAdd;
    do
    {
        printf("Enter Start Time [HH:MM]: ");
        scanf("%d:%d", &startHourAdd, &startMinAdd);
        getchar();
        if(startHourAdd < 0 || startHourAdd > 23 || startMinAdd < 0 || startMinAdd > 59)
        {
            printf("Invalid Time Format!\n");
        }
    }
    while (startHourAdd < 0 || 
    startHourAdd > 23 ||
    startMinAdd < 0 || 
    startMinAdd > 59);
    
    int endHourAdd;
    int endMinAdd;
    int addDuration;
    do
    {
        printf("Enter End Time [HH:MM]: ");
        scanf("%d:%d", &endHourAdd, &endMinAdd);
        getchar();
        if(endHourAdd < 0 || endHourAdd > 23 || endMinAdd < 0 || endMinAdd > 59)
        {
            printf("Invalid Time Format!\n");
        }
        addDuration = (endHourAdd - startHourAdd) * 60 + (endMinAdd - startMinAdd);
    } 
    while (endHourAdd < 0 ||
    endHourAdd > 23 ||
    endMinAdd < 0 ||
    endMinAdd > 59);

    int studioNum;
    do
    {
        printf("Enter Movie Studio [1-10]: ");
        scanf("%d", &studioNum);
        getchar();
        if(studioNum < 1 || studioNum > 10)
        {
            printf("Movie Studio Must Be Between 1 - 10!\n");
        }
    }
    while (studioNum < 1 || studioNum > 10);

    char movID[10];
    sprintf(movID, "MV%d%d%d", rand () %10, rand() % 10, rand() % 10);
    
    strcpy(data[size].id, movID);
    strcpy(data[size].movieName, name);
    data[size].startHour = startHourAdd;
    data[size].startMinute = startMinAdd;
    data[size].endHour = endHourAdd;
    data[size].endMinute = endMinAdd;
    data[size].duration = addDuration;
    data[size].studio = studioNum;

    size++;
    printf("Movie Added Successfully!\n");
    printf("Press Enter To Continue...");
    getchar();

    return;
}

void updateData()
{
    if(size == 0)
    {
        printf("Oops. No Movie Available!\n");
        printf("Press Enter To Continue...");
        getchar();
    }
    else
    {
        int select;
        for(int i = 0; i < size; i++)
        {
            printf("No.%d\n", i + 1);
            printf("Movie ID: %s\n", data[i].id);
            printf("Movie Name: %s\n", data[i].movieName);
            printf("Start Time: %d:%d\n", data[i].startHour, data[i].startMinute);
            printf("End Time: %d:%d\n", data[i].endHour, data[i].endMinute);
            printf("Duration: %d Minutes\n", data[i].duration);
            printf("Studio: %d\n", data[i].studio);
        }

        do
        {
            printf("Enter Movie Index to Update [1 - %d]: ", size);
            scanf("%d", &select);
            getchar();
        }
        while (select < 1 || select > size);
        
        char name[50];
        do
        {
            printf("Enter Movie Name [1-20 Characters]: ");
            scanf("%[^\n]", name);
            getchar();
            if(strlen(name) > 20 || strlen(name) < 1)
            {
                printf("Movie Name Must Be Between 1 - 20 Characters!\n");
            }
        }
        while (strlen(name) > 20 || strlen(name) < 1);

        int startHourAdd;
        int startMinAdd;
        do
        {
            printf("Enter Start Time [HH:MM]: ");
            scanf("%d:%d", &startHourAdd, &startMinAdd);
            getchar();
            if(startHourAdd < 0 || startHourAdd > 23 || startMinAdd < 0 || startMinAdd > 59)
            {
                printf("Invalid Time Format!\n");
            }
        }
        while (startHourAdd < 0 || 
        startHourAdd > 23 ||
        startMinAdd < 0 || 
        startMinAdd > 59);
        
        int endHourAdd;
        int endMinAdd;
        int addDuration;
        do
        {
            printf("Enter End Time [HH:MM]: ");
            scanf("%d:%d", &endHourAdd, &endMinAdd);
            getchar();
            if(endHourAdd < 0 || endHourAdd > 23 || endMinAdd < 0 || endMinAdd > 59)
            {
                printf("Invalid Time Format!\n");
            }
            addDuration = (endHourAdd - startHourAdd) * 60 + (endMinAdd - startMinAdd);
        } 
        while (endHourAdd < 0 ||
        endHourAdd > 23 ||
        endMinAdd < 0 ||
        endMinAdd > 59);

        int studioNum;
        do
        {
            printf("Enter Movie Studio [1-10]: ");
            scanf("%d", &studioNum);
            getchar();
            if(studioNum < 1 || studioNum > 10)
            {
                printf("Movie Studio Must Be Between 1 - 10!\n");
            }
        }
        while (studioNum < 1 || studioNum > 10);

        strcpy(data[select - 1].movieName, name);
        data[size - 1].startHour = startHourAdd;
        data[size - 1].startMinute = startMinAdd;
        data[size - 1].endHour = endHourAdd;
        data[size - 1].endMinute = endMinAdd;
        data[size - 1].duration = addDuration;
        data[size - 1].studio = studioNum;  
    }
    return;
}

void mainMenu()

void swap(Cinema *a, Cinema *b)
{
    Cinema temp = *a;
    *a = *b;
    *b = temp
}

{
    int input;
    while(true)
    {
        printf("1. View All Movies\n");
        printf("2. Add New Movies\n");
        printf("3. Update Movies\n");
        printf("4. Delete Movie\n");
        printf("5. Save and Exit\n");
        printf("Input [1-5]: ");
        scanf("%d", &input);
        fflush(stdin);

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
                updateData();
                break;
            }
        }
    }
    return;
}

int main()
{
    readFile();
    mainMenu();
    srand(0);
}
