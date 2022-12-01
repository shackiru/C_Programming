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
        printf("There is no file!\n");
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
            fgetc(f);

            data[size].duration = (data[size].endHr - data[size].startHr) * 60 + (data[size].endMnt - data[size].startMnt);

            size++;
        }
    }
    fclose(f);
}

void addData()
{
    char name[50];
    do
    {
        printf("Enter Movie Name [1 - 20 Characters]: ");
        scanf("%[^\n]", name);
        getchar();
        if(strlen(name) < 1 || strlen(name) > 20)
        {
            printf("Movie Name must be between 1 - 20 characters!\n");
        }
    } while (strlen(name) < 1 || strlen(name) > 20);
    
    int addStrHr;
    int addStrMnt;
    do
    {
        printf("Enter Start Time[HH:MM]: ");
        scanf("%d:%d", &addStrHr, &addStrMnt);
        getchar();
        fflush(stdin);
        if(addStrHr < 0 || addStrHr > 23 || addStrMnt < 0 || addStrMnt > 59)
        {
            printf("Invalid time format!\n");
        }
    } while (addStrHr < 0 || addStrHr > 23 || addStrMnt < 0 || addStrMnt > 59);

    int addEndHr;
    int addEndMnt;
    do
    {
        printf("Enter End Time[HH:MM]: ");
        scanf("%d:%d", &addEndHr, &addEndMnt);
        getchar();
        if(addEndHr < 0 || addEndHr > 23 || addEndMnt < 0 || addEndMnt > 59)
        {
            printf("Invalid time format!\n");
        }
    } while (addEndHr < 0 || addEndHr > 23 || addEndMnt < 0 || addEndMnt > 59);
    
    int addDur = (addEndHr - addStrHr) * 60 + (addEndHr - addStrHr);
    int addStudio;
    do
    {
        printf("Enter Movie Studio[1-10]: ");
        scanf("%d", &addStudio);
        getchar();
        if(addStudio < 1 || addStudio > 10)
        {
            printf("Movie Studio must be between 1 - 10!\n");
        }
    } while (addStudio < 1 || addStudio > 10);

    char id[105];
    sprintf(id, "MV%d%d%d", rand() % 10, rand() % 10, rand() % 10);
    strcpy(data[size].movID, id);
    strcpy(data[size].movName, name);
    data[size].startHr = addStrHr;
    data[size].startMnt = addStrMnt;
    data[size].endHr = addEndHr;
    data[size].endMnt = addEndMnt;
    data[size].duration = addDur;
    data[size].studio = addStudio;

    size++;
    printf("Movie added successfully!\n");
    printf("Press ENTER to continue...");
    getchar();
    
    return;
}

void updateData()
{
    if(size == 0)
    {
        printf("There is no data to update :(\n");
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            printf("No.%d\n", i + 1);
            printf("Movie ID: %s\n", data[i].movID);
            printf("Movie Name: %s\n", data[i].movName);
            printf("Start Time: %02d:%02d\n", data[i].startHr, data[i].startMnt);
            printf("End Time: %02d:%02d\n", data[i].endHr, data[i].endMnt);
            printf("Duration: %d Minutes\n", data[i].duration);
        }

        int update;
        do
        {
            printf("Enter Movie index to update [1 - %d]: ", size);
            scanf("%d", &update);
            getchar();
            fflush(stdin);
        } while (update < 1 || update > size);
        
        char name[50];
        do
        {
            printf("Enter Movie Name [1 - 20 Characters]: ");
            scanf("%[^\n]", name);
            getchar();
            if(strlen(name) < 1 || strlen(name) > 20)
            {
                printf("Movie Name must be between 1 - 20 characters!\n");
            }
        } while (strlen(name) < 1 || strlen(name) > 20);
    
        int addStrHr;
        int addStrMnt;
        do
        {
            printf("Enter Start Time[HH:MM]: ");
            scanf("%d:%d", &addStrHr, &addStrMnt);
            getchar();
            if(addStrHr < 0 || addStrHr > 23 || addStrMnt < 0 || addStrMnt > 59)
            {
                printf("Invalid time format!\n");
            }
        } while (addStrHr < 0 || addStrHr > 23 || addStrMnt < 0 || addStrMnt > 59);

        int addEndHr;
        int addEndMnt;
        do
        {
            printf("Enter End Time[HH:MM]: ");
            scanf("%d:%d", &addEndHr, &addEndMnt);
            getchar();
            if(addEndHr < 0 || addEndHr > 23 || addEndMnt < 0 || addEndMnt > 59)
            {
                printf("Invalid time format!\n");
            }
        } while (addEndHr < 0 || addEndHr > 23 || addEndMnt < 0 || addEndMnt > 59);
        
        int addDur = (addEndHr - addStrHr) * 60 + (addEndHr - addStrHr);
        int addStudio;
        do
        {
            printf("Enter Movie Studio[1-10]: ");
            scanf("%d", &addStudio);
            getchar();
            if(addStudio < 1 || addStudio > 10)
            {
                printf("Movie Studio must be between 1 - 10!\n");
            }
        } while (addStudio < 1 || addStudio > 10);

        strcpy(data[update - 1].movName, name);
        data[update - 1].startHr = addStrHr;
        data[update - 1].startMnt = addStrMnt;
        data[update - 1].endHr = addEndHr;
        data[update - 1].endMnt = addEndMnt;
        data[update - 1].duration = addDur;
        data[update - 1].studio = addStudio;

        printf("Data updated successfully!\n");
        printf("Press ENTER to continue...\n");
        getchar();
    }
    return;
}

void deleteData()
{
    if(size == 0)
    {
        printf("Oops. There is no such movie :(\n");
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            printf("No.%d\n", i + 1);
            printf("Movie ID: %s\n", data[i].movID);
            printf("Movie Name: %s\n", data[i].movName);
            printf("Start Time : %02d:%02d\n", data[i].startHr, data[i].startMnt);
            printf("End Time: %02d:%02d\n", data[i].endHr, data[i].endMnt);
            printf("Duration: %d Minutes\n", data[i].duration);
        }

        int del;
        do
        {
            printf("Choose index to delete [1 - %d]: ", size);
            scanf("%d", &del);
            fflush(stdin);
        } while (del < 1 || del > size);

        for(int x = del - 1; x < size - 1; x++)
        {
            strcpy(data[x].movID, data[x + 1].movID);
            strcpy(data[x].movName, data[x + 1].movName);
            data[x].startHr = data[x + 1].startHr;
            data[x].startMnt = data[x + 1].startMnt;
            data[x].endHr = data[x + 1].endHr;
            data[x].endMnt = data[x + 1].endMnt;
            data[x].duration = data[x + 1].duration;
            data[x].studio = data[x + 1].studio;
        }   

        strcpy(data[size - 1].movID, "");
        strcpy(data[size - 1].movName, "");
        data[size - 1].startHr = 0;
        data[size - 1].startMnt = 0;
        data[size - 1].endHr = 0;
        data[size - 1].endMnt = 0;
        data[size - 1].duration = 0;
        data[size - 1].studio = 0;

        size--;
        printf("Data delete successfully!\n");
        printf("Press enter to continue...");
        getchar();
    }
    return;
}

void saveData()
{
    FILE *fp = fopen("cinema2", "w");

    for(int j = 0; j < size; j++);
    {
        fprintf(fp, "%s,%s,%d:%d,%d:%d,%d",
        data[size].movID,
        data[size].movName,
        data[size].startHr,
        data[size].startMnt,
        data[size].endHr,
        data[size].endMnt,
        data[size].studio);
    }
    fclose(fp);
    exit(0);

    return;
}

void swap(Cinema *a, Cinema *b)
{
    Cinema temp = *a;
    *a = *b;
    *b = temp;
}

int partitionID(int low, int high)
{
	char pivot[10];
	strcpy(pivot, data[high].movID);
	
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

void quickSortID(int low, int high)
{
    if(low < high)
    {
        int pivot = (partitionID(low, high));
        quickSortID(low, pivot - 1);
        quickSortID(pivot + 1, high);
    }
}

int partitionName(int low, int high)
{
    char pivot[10];
    strcpy(pivot, data[high].movName);

    int i = low - 1;
    for(int j = low; j < high; j++)
    {
        if(strcmp(data[j].movName, pivot) < 0)
        {
            i++;
            swap(&data[j], &data[i]);
        }
    }
    swap(&data[i + 1], &data[high]);
    return i + 1;
}

void quickSortName(int low, int high)
{
    if(low < high)
    {
        int pivot(partitionName(low, high));
        quickSortName(low, pivot - 1);
        quickSortName(pivot + 1, high);
    }
}

int partitionDur(int low, int high)
{
    int pivot;
    int i = low - 1;

    for(int j = low; j < high; j++)
    {
        if(data[size].duration)
        {
            i++;
            swap(&data[j], &data[i]);
        }
    }
    swap(&data[i + 1], &data[high]);
    return i + 1;
}

void quickSortDur(int low, int high)
{
    if(low < high)
    {
        int pivot(partitionDur(low, high));
        quickSortDur(low, pivot - 1);
        quickSortDur(pivot + 1, high);
    }
}

void displayID()
{
    for(int v = 0; v < size; v++)
        {
            printf("No.%d\n", v + 1);
            printf("Movie ID: %s\n", data[v].movID);
            printf("Movie Name %s\n", data[v].movName);
            printf("Start Time : %02d:%02d\n", data[v].startHr, data[v].startMnt);
            printf("End Time: %02d:%02d\n", data[v].endHr, data[v].endMnt);
            printf("Duration: %d Minutes\n", data[v].duration);
        }
    return;
}

void displayName()
{
    for(int i = 0; i < size; i++)
        {
            printf("No.%d\n", i + 1);
            printf("Movie ID: %s\n", data[i].movID);
            printf("Movie Name %s\n", data[i].movName);
            printf("Start Time : %02d:%02d\n", data[i].startHr, data[i].startMnt);
            printf("End Time: %02d:%02d\n", data[i].endHr, data[i].endMnt);
            printf("Duration: %d Minutes\n", data[i].duration);
        }
        return;
}

void displayDur()
{
    for(int i = 0; i < size; i++)
        {
            printf("No.%d\n", i + 1);
            printf("Movie ID: %s\n", data[i].movID);
            printf("Movie Name %s\n", data[i].movName);
            printf("Start Time : %02d:%02d\n", data[i].startHr, data[i].startMnt);
            printf("End Time: %02d:%02d\n", data[i].endHr, data[i].endMnt);
            printf("Duration: %d Minutes\n", data[i].duration);
        }
    return;
}

void displayAll()
{
    if(size == 0)
    {
        printf("Oops. No Movie Available!\n");
        printf("Press ENTER To Continue...");
        getchar();
    }
    else
    {
        for(int i = 0; i < size; i++)
        {
            printf("No.%d\n", i + 1);
            printf("Movie ID: %s\n", data[i].movID);
            printf("Movie Name %s\n", data[i].movName);
            printf("Start Time : %02d:%02d\n", data[i].startHr, data[i].startMnt);
            printf("End Time: %02d:%02d\n", data[i].endHr, data[i].endMnt);
            printf("Duration: %d Minutes\n", data[i].duration);
        }

        int select;

        printf("Select by Sort\n");
        printf("1. ID\n");
        printf("2. Name\n");
        printf("3. Duration\n");
        printf("4. Back\n");
        printf("Select:");
        scanf("%d", &select);
        fflush(stdin);

        switch(select)
        {
            case 1:
            {
                quickSortID(0, size - 1);
                displayID();
                break;
            }
            case 2:
            {
                quickSortName(0, size - 1);
                displayName();
                break;
            }
            case 3:
            {
                quickSortDur(0, size - 1);
                displayDur;
                break;
            }
            case 4:
            {
                return;
                break;
            }
        }
    }
}

void mainMenu()
{
    int input;

    while(true)
    {
        printf("Hi, there!\n");
        printf("1. View All Movie\n");
        printf("2. Add New Movie\n");
        printf("3. Update Movie\n");
        printf("4. Delete Movie\n");
        printf("5. Save and Exit\n");
        printf("Input [1 - 5]: ");
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
            case 4:
            {
                deleteData();
                break;
            }
            case 5:
            {
                saveData();
                break;
            }
            default:
            {
                printf("Invalid Number!\n");
                break;
            }
        }
    }
}

int main()
{
    readFile();
    mainMenu();

    return 0;
}
