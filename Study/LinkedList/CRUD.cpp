#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}nd;

nd *head = NULL;

void check(char *word, int *var)
{
    int temp;
    printf(word);

    scanf("%d", &temp);
    *var = temp;

    fflush(stdin);
}

void add()
{
    nd *temp, *ptr;
    temp = (nd*) malloc (sizeof(nd));

    if(temp == NULL)
    {
        printf("There is no memory space!\n");
    }

    check("Input data: ", &temp->data);
    temp -> next = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while(ptr -> next != NULL)
        {
            ptr = ptr -> next;
        }
        ptr -> next = temp;
    }
}

void displayData()
{
    nd *ptr;
    int i = 0;

    if(head == NULL)
    {
        printf("Data not found!\n");
        system("PAUSE\n");
        return;
    }
    else
    {
        ptr = head;
        printf("List data: \n");
        printf("Index\t|\t Data\n");
        while(ptr != NULL)
        {
            printf("%d \t!", i);
            printf("\t%d\n", ptr -> data);
            ptr = ptr -> next;
            i++;
        }
    }
}

void firstInput()
{
    nd *temp;
    temp = (Node *) malloc (sizeof(nd));

    if(temp == NULL)
    {
        printf("There is no memory space!\n");
        return;
    }
    check("Input number: ", &temp -> data);
    temp -> next = head;
    head = temp;
}

void lastInput()
{
    nd *temp, *ptr;
    temp = (nd*) malloc (sizeof(nd));

    if(temp == NULL)
    {
        printf("There is no memory space!\n");
        return;
    }
    check("Input number: ", &temp -> data);
    temp -> next = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while(ptr -> next != NULL)
        {
            ptr = ptr -> next;
        }
        ptr -> next = temp;
    }
}

void indexInput()
{
    nd *ptr, *temp;
    int i, position;
    temp = (nd*) malloc(sizeof(nd));

    if(temp == NULL)
    {
        printf("There is no memory space!\n");
        return;
    }

    displayData();

    printf("\nIndex start from 0\n");
    printf("Input index to input a new node: ", &position);
    printf("\nInput number: ", &temp -> data);

    temp -> next = NULL;
    if(position == 0)
    {
        temp -> next = head;
        head = temp;
    }
    else
    {
        for(i = 0, ptr = head; i < position - 1; i++)
        {
            ptr = ptr -> next;
            if(ptr == NULL)
            {
                printf("Index not found!\n");
                return;
            }
        }
        temp -> next = ptr -> next;
        ptr -> next = temp;
    }
}

void update()
{
    int i, position;
    nd *temp, *ptr;
    
    if(head == NULL)
    {
        printf("List not found!\n");
    }
    else
    {
        displayData();
        printf("\nIndex start from 0!\n");
        check("\nInput Index to update data: ", &position);
    }
}