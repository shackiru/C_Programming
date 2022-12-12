#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int number;
    Node *prev;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

Node* create(int x)
{
    Node *temp = (Node*) malloc (sizeof(struct Node));
    temp -> number = x;
    temp -> prev = NULL;
    temp -> next = NULL;
    return temp;
}

void addData()
{

}

void sortData()
{

}

void searchData()
{

}

int main()
{
    int menu;
    while(true)
    {
        printf("1. Add Data\n");
        printf("2. Sort Data\n");
        printf("3. Search Data\n");
        printf("Choose Menu: ");

        scanf("%d", &menu);
        fflush(stdin);
        
        switch(menu)
        {
            case 1:
            {
                addData();
                break;
            }    
            case 2:
            {
                sortData();
                break;
            }
            case 3:
            {
                searchData();
                break;
            }
            default:
            {
                printf("Invalid input number!\n");
                break;
            }
        }
    }

    return 0;
}