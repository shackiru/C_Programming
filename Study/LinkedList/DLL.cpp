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

    printf("Enter the Salary of the Employee: ");
    scanf("%f", &salary);
    getchar();

    printf("Enter the Phone Number of the Employee: ");
    scanf("%ld", &phone);
    getchar();

    temp->SSN = SSN;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->design, design);
    temp->salary = salary;
    temp->phone = phone;

    size++;
}

void firstInsert()
{
    if(h == NULL)
    {
        create();
        h = temp;
        temp2 = h;
    }
    else
    {
        create();
        temp->next = h;
        h->prev = temp;
        h = temp;
    }
}

void lastInsert()
{
    if(h == NULL)
    {
        create();
        h = temp;
        temp2 = h;
    }
    else
    {
        create();
        temp2->next = temp;
        temp->prev = temp2;
        temp2 = temp;
    }
}

void displayFirst()
{
    temp3 = h;
    if(temp3 == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }
    else
    {
        printf("\nLinked List elements from the beginning: \n");
        while(temp3 != NULL)
        {
            printf("SSN\t: %d\n", temp3->SSN);
            printf("Name\t: %s\n", temp3->name);
            printf("Department\t: %s\n", temp3->dept);
            printf("Designation\t: %s\n", temp3->design);
            printf("Salary\t: %f\n", temp3->salary);
            printf("Phone Number\t: %ld\n", temp3->phone);
            temp3 = temp3->next;
        }
        printf("Number of Employees\t: %d", size);
    }
}

int deleteFirst()
{
    struct Node *temp;
    temp = h;
    if(temp == NULL)
    {
        printf("\nList is empty!\n");
        return 0;
    }
    if(temp->next == NULL)
    {
        printf("SSN\t: %d\n", temp3->SSN);
        printf("Name\t: %s\n", temp3->name);
        printf("Department\t: %s\n", temp3->dept);
        printf("Designation\t: %s\n", temp3->design);
        printf("Salary\t: %f\n", temp3->salary);
        printf("Phone Number\t: %ld\n", temp3->phone);
        free(temp);
        h = NULL;
    }
    else
    {
        h = h->next;
        h->prev = NULL;
        printf("SSN\t: %d\n", temp3->SSN);
        printf("Name\t: %s\n", temp3->name);
        printf("Department\t: %s\n", temp3->dept);
        printf("Designation\t: %s\n", temp3->design);
        printf("Salary\t: %f\n", temp3->salary);
        printf("Phone Number\t: %ld\n", temp3->phone);
        free(temp);
    }
    size--;
    return 0;
}

int deleteLast()
{
    struct Node *temp;
    temp = h;
    if(temp == NULL)
    {
        printf("\nList is empty!\n");
        return 0;
    }
}