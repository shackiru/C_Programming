#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct menu
{
    char menuName;
    int menuPrice;

    struct menu *next, *prev;
};

struct customer
{
    char custName;
    char custMember;

    struct menu *next, prev;
};

struct customerRow
{
    struct customerRow *head, *tail;
};

struct menuRow
{   
    struct menuRow *head, *tail;
};

struct orderQueue
{

};

void readCustomer()
{

}

void readMenu()
{

}

int main()
{

    return 0;
}