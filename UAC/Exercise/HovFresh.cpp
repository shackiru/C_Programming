#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct menu
{
    char menuName[55];
    int menuPrice;

    struct menu *next, *prev;
};

struct customer
{
    int custID;
    char custName[55];
    int custMember;

    struct menu *next, *prev;
};

struct customerRow
{
    struct customer *head = NULL, *tail = NULL;
};

struct menuRow
{   
    struct menu *head = NULL, *tail = NULL;
};

struct orderQueue
{

};

struct customerRow *customerList;
struct menuRow *menuList;

struct customerRow * createCustomerRow()
{
    struct customerRow *temp = (struct customerRow*) malloc (sizeof(customerRow));
    temp->head = temp->tail = NULL;

    return temp;
}

struct customer *addCustomer(const int id, const char name[], const int member)
{
    customer *newCustomer = (struct customer*) malloc (sizeof(customer));
    newCustomer->custID = id;
    strcpy(newCustomer->custName, name);
    newCustomer->custMember = member;
    newCustomer->next = newCustomer->prev = NULL;
    
    return newCustomer;
}

void readCustFile()
{
    FILE * f = fopen("customers.txt", "r");
    if(f == NULL)
    {
        printf("File not found...\n");
        return;
    }
    else
    {
        int i = 0;
        while(feof(f) == NULL)
        {
            int ID;
            char name[55];
            int membership;

            fscanf(f, "%d#%[^#]#%d", &ID, name, &membership);
            fgetc(f);

            addCustomer(ID, name, membership);
        }
    }
    fclose(f);
}

void readMenuFile()
{
    FILE * fp = fopen("menus.txt", "r");
    if(fp == NULL)
    {
        printf("File not found...\n");
    }
    else
    {
        while(feof(fp) == NULL)
        {
            int menuID;
            char menuName[55];
            int price;
            fscanf(fp, "%d#%[^#]#%d\n", &menuID, menuName, &price);
        }
    }
    fclose(fp);
}

int main()
{
    readCustFile();

    return 0;
}