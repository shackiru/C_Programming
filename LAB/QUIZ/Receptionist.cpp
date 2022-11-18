#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Visitor
{
    char id[7];
    char name[105];
    int age;

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
    fclose(fp);
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

    strcpy(visitorArr[size].id, visitorID);
    strcpy(visitorArr[size].name, visitorName);
    visitorArr[size].age = visitorAge;
    size++;
    
    printf("Visitor Has Been Updated!\n");
}

void merge(int left, int mid, int right)
{
	int sizeLeft = mid - left + 1;
	int sizeRight = right - mid;
	
	Visitor leftArr[sizeLeft];
	Visitor rightArr[sizeRight];
	
	for(int i = 0; i < sizeLeft; i++)
	{
		leftArr[i] = visitorArr[left + i];
	}
	
	for(int j = 0; j < sizeRight; j++)
	{
		rightArr[j] = visitorArr[mid + j + 1];
	}
	
	int indexLeft = 0;
	int indexRight = 0;
	int indexArray = left;
	
	while(indexLeft < sizeLeft && indexRight < sizeRight)
	{
		if(strcmp(leftArr[indexLeft].id, rightArr[indexRight].id) <= 0)
		{
			visitorArr[indexArray] = leftArr[indexLeft];
			indexLeft++;
		}
		else
		{
			visitorArr[indexArray] = rightArr[indexRight];
			indexRight++;
		}
		indexArray++;
	}
	
	while(indexLeft < sizeLeft)
	{
		visitorArr[indexArray] = leftArr[indexLeft];
		indexLeft++;
		indexArray++;
	}
	
	while(indexLeft < sizeLeft)
	{
		visitorArr[indexArray] = rightArr[indexRight];
		indexRight++;
		indexRight++;
	}
}

void mergeSort(int left, int right)
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}

void swap(Visitor *a, Visitor *b)
{
	Visitor temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int low, int high)
{
	char pivot [10];
	
	strcpy(pivot, visitorArr[low].id);
	int leftToRight = low; // i lebih besar dari pivot
	int rightToLeft = high; // j lebih kecil dari pivot
	
	while(leftToRight < rightToLeft)
	{
		do
		{
			leftToRight++;
		}
		while(strcmp(visitorArr[leftToRight].id, pivot) <= 0);
		
		do
		{
			rightToLeft--;
		}
		while(strcmp(visitorArr[rightToLeft].id, pivot) > 0);
		
		if(leftToRight < rightToLeft)
		{
			swap(&visitorArr[leftToRight], &visitorArr[rightToLeft]);
		}
	}
	swap(&visitorArr[low], &visitorArr[rightToLeft]);
	return rightToLeft;
}

void quickSort(int low, int high)
{
	if(low < high)
	{
		int pivot = (partition(low, high));
		quickSort(low, pivot - 1);
		quickSort(pivot + 1, high);
	}
}

void viewData()
{
    quickSort(0, size);
    //mergeSort(0, size - 1);
	displayAll();
}

void deleteData()
{
	if(size == 0)
	{
		printf("No data to delete!\n");
		return;
	}
	
	mergeSort(0, size - 1);
	displayAll();
	
	int inputDelete;
	do
	{
		printf("Input Index to Delete [1 - %d]: ", size);
		scanf("%d", &inputDelete);
		if(inputDelete < 1 || inputDelete > size)
		{
			printf("Invalid Number!\n");
		}
		getchar();
	}
	while(inputDelete < 1 || inputDelete > size);
	
	for(int i = inputDelete - 1; i < size - 1; i++)
	{
		visitorArr[i] = visitorArr[i + 1];
	}
	
	strcpy(visitorArr[size - 1].id, "");
	strcpy(visitorArr[size - 1].name, "");
	visitorArr[size - 1].age = 0;
	
	size--;
	printf("Visitor Has Been Deleted!\n");
}

void saveData()
{
	FILE *f = fopen("visitors.txt", "w");
	for(int i = 0; i < size; i++)
	{
		fprintf(f, "%s#%s#%d\n", visitorArr[i].id, visitorArr[i].name, visitorArr[i].age);
	}
	fclose(f);
	exit(0);
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
    //displayAll();
    mainMenu();

    return 0;
}
