#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0;

struct Node
{
    struct Node *prev;
    struct Node *next;

    int SSN;
    long int phone;
    float salary;
    char name[105];
    char dept[105];
    char design[105];
}*h, *temp, *temp2, *temp3, *temp4;

void create()
{
    int SSN;
    long int phone;
    float salary;
    char name[105];
    char dept[105];
    char design[105];

    temp = (struct Node*) malloc (sizeof(struct Node));
    temp->prev = NULL;
    temp->next = NULL;
    printf("\n Enter the SSN of the Employee: ");
    scanf("%d", &SSN);
    getchar();

    printf("\n Enter the Name of the Employee: ");
    scanf("%[^\n]", name);
    getchar();

    printf("Enter the Department of the Employee: ");
    scanf("%s", dept);
    getchar();

    printf("Enter the Designation of the Employee: ");
    scanf("%s", design);
    getchar();
    
}