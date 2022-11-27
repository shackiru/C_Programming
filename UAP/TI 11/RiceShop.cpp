#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Rice
{
    char customerName[105]= {};
    char riceType[105] = {};
    char riceTopping[105] = {};
    int ricePrice;
    int riceQuantity;
};

Rice r [105];
int size = 0;

void readFile()
{
    FILE * f = fopen("data.csv", "r");
    if(f == NULL)
    {
        return;
    }

    while(!feof(f))
    {
        fscanf(f, "%[^#]#%[^#]#%[^#]#%d#%d\n", r[size].customerName, r[size].riceType, r[size].riceTopping, &r[size].ricePrice, &r[size].riceQuantity);
        size++;
    }
    fclose(f);
}

void swap(Rice *a, Rice *b)
{
    Rice temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int low, int high)
{
    char pivot[105];
    strcpy(pivot, r[low].customerName);
    int leftToRight = low;
    int rightToLeft = high;

    while(leftToRight < rightToLeft)
    {
        do
        {
            leftToRight++;
        }
        while(strcmp(r[leftToRight].customerName, pivot) <= 0);

        do
        {
            rightToLeft--;
        } 
        while(strcmp(r[rightToLeft].customerName, pivot) > 0);

        if(leftToRight < rightToLeft)
        {
            swap(&r[leftToRight], &r[rightToLeft]);
        }
        
    }
    swap(&r[low], &r[high]);
    return rightToLeft;
}

void quickSortName(int low, int high)
{
    if(low < high)
    {
        int pivot = partition(low, high);
        quickSortName(low, pivot - 1);
        quickSortName(pivot + 1, high);
    }
}

void addData()
{
    char name[105];
    char chooseRice[105];
    char chooseTopping[105];
    int quantity;
    
    do
    {
        printf("Insert Customer name [3- 50 characters]:");
        scanf("%s", name);
        if(strlen(name) < 3 || strlen(name) > 50)
        {
            printf("Input Valid Name!\n");
        }
        getchar();
    }
    while(strlen(name) < 3 || strlen(name) > 50);
    
    do
    {
        printf("Choose fried rice :\n");
        printf("1. Vegetarian fried rice\n");
        printf("2. Pork fried rice\n");
        printf("3. Beef fried rice\n");
        printf("4. Chicken fried rice\n");
        printf("Choose fried rice [1 - 4] :");
        scanf("%s", chooseRice);
        if(strcpy(chooseRice, "1"))
        {
            chooseRice[size] = 'Vegetarian fried rice';
        }
        else if(strcpy(chooseRice, "2"))
        {
            chooseRice[size] = 'Pork fried rice';
        }
        else if(strcpy(chooseRice, "3"))
        {
            chooseRice[size] = 'Beef fried rice';
        }
        else if(strcpy(chooseRice, "4"))
        {
            chooseRice[size] = 'Chicken fried rice';
        }
        else
        {
            printf("Input the valid number\n");
        }
        getchar();
    } 
    while(strlen(chooseRice) < 1 || strlen(chooseRice) > 4);

    do
    {
        printf("Choose topping:\n");
        printf("1. Omelette\n");
        printf("2. Mozarella\n");
        printf("3. Cheddar\n");
        printf("Choose fried rice [1 - 3]:");
        scanf("%s", &chooseTopping);
        if(strcpy(chooseTopping, "1"))
        {
            chooseTopping[size] = 'Omelette';
        }
        else if(strcpy(chooseTopping, "2"))
        {
            chooseTopping[size] = 'Mozarella';
        }
        else if(strcpy(chooseTopping, "3"))
        {
            chooseTopping[size] = 'Cheddar';
        }
        else
        {
            printf("Input the valid number\n");
        }
        getchar();
    } 
    while (strlen(chooseTopping) < 1 || strlen(chooseTopping) > 3);

    do
    {
        printf("Insert quantity of fried rice [1 - 10]: ");
        scanf("%d", &quantity);
        getchar();
    } 
    while (quantity < 1 | quantity > 10);
    
    strcpy(r[size].customerName, name);
    strcpy(r[size].riceType, chooseRice);
    strcpy(r[size].riceTopping, chooseTopping);
    r[size].riceQuantity = quantity;
    size++;    
}

void displayAll()
{
    for(int i = 0; i < size; i++)
    {
        printf("%d. %s\n", i + 1, r[i].riceType);
        printf("Ordered by - %s with quantity of %d, price of 0 total of 0\n", 
        r[i].customerName, 
        r[i].riceQuantity);
    }   
}

void displayDataName()
{
    quickSortName(0, size);
    displayAll();
}

void displayData()
{
    int order;
    displayAll();
    printf("1. Order by price\n");
    printf("2. Order by quantity\n");
    printf("3. Order by customer name\n");
    printf("4. Exit\n");
    printf("Choose > "); 
    scanf("%d", &order);
    fflush(stdin);

    switch(order)
    {
        case 1:
        {
            break;
        }
        case 2:
        {
            break;
        }
        case 3:
        {
            displayDataName();
            break;
        }
        case 4:
        {
            break;
        }
        default:
        {
            printf("Input Valid Number!\n");
        }
    }
}

void showMenu()
{
    int n;

    while(true)
    {
        printf("Random Fried Rice Shop...\n");
        printf("Current Money: \n");
        printf("1. Insert Order\n");
        printf("2. View Order\n");
        printf("3. Delete Order\n");
        printf("4. Exit\n");
        printf("Choose > ");
        scanf("%d", &n);
        fflush(stdin);

        switch(n)
        {
            case 1:
            {
                addData();
                break;
            }
            case 2:
            {
                displayData();
                break;
            }
            default:
            {
                printf("Invalid Input!\n");
            }
        }
    }
}

int main()
{
    readFile();
    showMenu();
    return 0;
}
