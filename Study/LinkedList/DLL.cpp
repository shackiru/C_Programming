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
    char phone[105];
    float salary;
    char name[105];
    char dept[105];
    char design[105];
}*h, *temp, *temp2, *temp3, *temp4;

void create()
{
    int SSN;
    char phone[105];
    float salary;
    char name[105];
    char dept[105];
    char design[105];

    temp = (struct Node*) malloc (sizeof(struct Node));
    temp->prev = NULL;
    temp->next = NULL;

    printf("==========Input the Employee Data==========\n");
    printf("Enter the SSN of the Employee\t\t: ");
    scanf("%d", &SSN);
    getchar();

    printf("Enter the Name of the Employee\t\t: ");
    scanf("%[^\n]", name);
    getchar();

    printf("Enter the Department of the Employee\t: ");
    scanf("%[^\n]", dept);
    getchar();

    printf("Enter the Designation of the Employee\t: ");
    scanf("%[^\n]", design);
    getchar();

    printf("Enter the Salary of the Employee\t: ");
    scanf("%f", &salary);
    getchar();

    printf("Enter the Phone Number of the Employee\t: ");
    scanf("%s", phone);
    getchar();
    printf("\n");

    temp->SSN = SSN;
    strcpy(temp->name, name);
    strcpy(temp->dept, dept);
    strcpy(temp->design, design);
    strcpy(temp->design, design);
    temp->salary = salary;
    strcpy(temp->phone, phone);

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
            printf("SSN\t\t: %d\n", temp3->SSN);
            printf("Name\t\t: %s\n", temp3->name);
            printf("Department\t: %s\n", temp3->dept);
            printf("Designation\t: %s\n", temp3->design);
            printf("Salary\t\t: %0.2f\n", temp3->salary);
            printf("Phone Number\t: %s\n", temp3->phone);
            printf("\n");
            temp3 = temp3->next;
        }
        printf("Number of Employees\t: %d\n", size);
        system("PAUSE");
    }
}

int deleteFirst()
{
    struct Node* temp;
    temp = h;
    if(temp == NULL)
    {
        printf("\nList is empty!\n");
        return 0;
    }
    if(temp->next == NULL)
    {
        printf("SSN\t\t: %d\n", temp->SSN);
        printf("Name\t\t: %s\n", temp->name);
        printf("Department\t: %s\n", temp->dept);
        printf("Designation\t: %s\n", temp->design);
        printf("Salary\t\t: %0.2f\n", temp->salary);
        printf("Phone Number\t: %s\n", temp->phone);
        free(temp);
        h = NULL;
    }
    else
    {
        h = h->next;
        h->prev = NULL;
        printf("SSN\t\t: %d\n", temp->SSN);
        printf("Name\t\t: %s\n", temp->name);
        printf("Department\t: %s\n", temp->dept);
        printf("Designation\t: %s\n", temp->design);
        printf("Salary\t\t: %02.f\n", temp->salary);
        printf("Phone Number\t: %s\n", temp->phone);
        free(temp);
    }
    size--;
    system("PAUSE");
    return 0;
}

int deleteLast()
{
    struct Node* temp;
    temp = h;
    if(temp == NULL)
    {
        printf("\nList is empty!\n");
        return 0;
    }
    if(temp->next == NULL)
    {
        printf("SSN\t\t: %d\n", temp->SSN);
        printf("Name\t\t: %s\n", temp->name);
        printf("Department\t: %s\n", temp->dept);
        printf("Designation\t: %s\n", temp->design);
        printf("Salary\t\t: %0.2f\n", temp->salary);
        printf("Phone Number\t: %s\n", temp->phone);
        free(temp);
        h = NULL;
    }
    else
    {
        temp = temp2;
        temp3 = temp2->prev;
        temp3->next = NULL;
        printf("SSN\t\t: %d\n", temp->SSN);
        printf("Name\t\t: %s\n", temp->name);
        printf("Department\t: %s\n", temp->dept);
        printf("Designation\t: %s\n", temp->design);
        printf("Salary\t\t: %0.2f\n", temp->salary);
        printf("Phone Number\t: %s\n", temp->phone);
        free(temp);
        temp2 = temp3;
    }
    size--;
    system("PAUSE");
    return 0;
}

void detail()
{
    int menu, amount;
    h = NULL;
    temp = temp2 = NULL;
    while(true)
    {
        system("CLS");
        printf("----------Menu----------\n");
        printf("1. Create a DLL of Employee\n");
        printf("2. Display from the beginning\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Delete at the beginning\n");
        printf("6. Delete at the end\n");
        printf("7. Exit\n");

        printf("Choose the menu: ");
        scanf("%d", &menu);
        fflush(stdin);

        switch(menu)
        {
            case 1:
            {
                printf("Enter number of employees\t: ");
                scanf("%d", &amount);
                fflush(stdin);
                printf("\n");
                for(int i = 0; i < amount; i++)
                {
                    lastInsert();
                    system("PAUSE");
                }
                break;
            }
            case 2:
            {
                displayFirst();
                break;
            }
            case 3:
            {
                firstInsert();
                system("PAUSE");
                break;
            }
            case 4:
            {
                lastInsert();
                system("PAUSE");
                break;
            }
            case 5:
            {
                deleteFirst();
                break;
            }
            case 6:
            {
                deleteLast();
                break;
            }
            case 7:
            {
                exit(0);
                system("PAUSE");
            }
            default:
            {
                printf("Wrong Choice!\n");
            }
        }
    }
}

int main()
{
    detail();

    return 0;
}
