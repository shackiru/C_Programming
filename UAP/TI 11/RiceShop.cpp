#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Rice
{
    char customerName[105]= {};
    char riceType[105];
    char riceTopping[105];
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

void showMenu()
{

}

void addData()
{
    char name[105];
    int chooseRice;
    
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
        printf("2. Prok fried rice\n");
        printf("3. Beef fried rice\n");
        printf("4. Chicken fried rice");
        scanf("%d", chooseRice);
        if()
        getchar();
    } 
    while();
    
}

int main()
{

    return 0;
}