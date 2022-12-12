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

void inputByIndex()
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

        if(position == 0)
        {
            ptr = head;
            head = head -> next;
            printf("\nUpdated Data: %d", ptr -> data);
            check("\nInput new data[Number]: ", &ptr -> data);
            system("PAUSE");
        }
        else
        {
            ptr = head;
            for(i = 0; i < position; i++)
            {
                temp = ptr;
                ptr = ptr -> next;
                if(ptr == NULL)
                {
                    printf("\nIndex not found!\n");
                    system("PAUSE");
                    return;
                }
            }
            temp -> next = ptr -> next;
            printf("\nUpdated Data: %d", ptr -> data);
            check("\nInput new Data [Number]: ", &ptr -> data);
            system("PAUSE");
        }
    }
}

void firstDelete()
{
    nd *ptr;
    if(head == NULL)
    {
        printf("Data not found!\n");
        return;
    }
    else
    {
            ptr = head;
            head = head -> next;

            printf("Deleted data: %d", ptr -> data);
            free(ptr);

            printf("\nData Successfully Deleted!\n");
            system("PAUSE");
    }
}

void lastDelete()
{
    nd *temp, *ptr;
    if(head == NULL)
    {
        printf("List not found!\n");
    }
    else if(head -> next == NULL)
    {
        ptr = head;
        while(ptr -> next != NULL)
        {
            temp = ptr;
            ptr = ptr -> next;
        }

        temp -> next = NULL;
        printf("Data to be deleted: %d", ptr -> data);
        free(ptr);
        printf("\nData deleted successful!\n");
        system("PAUSE");
    }
}

void deleteByIndex()
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
        printf("\nIndex started from 0");
        check("Input index to be deleted: ", &position);

        if(position == 0)
        {
            ptr = head;
            head = head -> next;
            printf("Data to be deleted: %d", ptr -> data);
            free(ptr);
            printf("\nData Deleted Successful!\n");
            system("PAUSE");
        }
    }
}

void menuAdd()
{
    int menu;
    if(head == NULL)
    {
        add();
    }
    else
    {
        system("CLS");
        printf("1. First Input\n");
        printf("2. Last Input\n");
        printf("3. Input By Index\n");
        printf("Choose Menu: ");
        scanf("%d", &menu);
        switch(menu)
        {
            case 1:
            {
                firstInput();
                break;
            }
            case 2:
            {
                lastInput();
                break;
            }
            case 3:
            {        
                inputByIndex();
                break;
            }
            default:
            {
                printf("Invalid menu input!\n");
                system("PAUSE");
            }
        }
    }
}

void menuDelete()
{
    int menu;
    printf("1. First Delete\n");
    printf("2. Last Delete\n");
    printf("3. Delete by Index\n");
    printf("Choose Menu: ");
    scanf("%d", &menu);

    switch(menu)
    {
        case 1:
        {
            firstDelete();
            break;
        }
        case 2:
        {         
            lastDelete();
            break;
        }
        case 3:
        {
            deleteByIndex();
            break;
        }
        default:
        {
            printf("Invalid menu input!\n");
            system("PAUSE");
        }
    }
}

void searchData()
{
    int target;
    int i = 0;
    nd *ptr;

    if(head == NULL)
    {
        printf("Data not found!\n");
        return;
    }
    else
    {
        check("Input data to be search[Number]: ", &target);
        ptr = head;

        if(ptr != NULL)
        {
            while(ptr != NULL)
            {
                if(ptr -> data == target)
                {
                    i++;
                }
                ptr = ptr -> next;
            }
            printf("Amount of data founded: %d\n", i);
            system("PAUSE");
            return;
        }
        if(ptr == NULL)
        {
            printf("Data not found!\n");
            system("PAUSE");
            return;
        }
    }
}

int main()
{
    int menu, checkMenu = 0;

    do
    {
        printf("1. Add Data\n");
        printf("2. Display Data\n");
        printf("3. Delete Data\n");
        printf("4. Search Data\n");
        printf("5. Update Data\n");
        printf("6. Exit\n");

        system("CLS");
        printf("Choose Menu: ");
        scanf("%d", &menu);

        switch(menu)
        {
            case 1:
            {
                menuAdd();
                break;
            }
            case 2:
            {
                displayData();
                break;
            }
            case 3:
            {
                menuDelete();
                break;
            }
            case 4:
            {
                searchData();
                break;
            }
            case 5:
            {
                update();
                break;
            }
            case 6:
            {
                exit(0);
            }
            default:
            {
                checkMenu = 1;
                break;
            }
        }
    }
    while (checkMenu != 1);
    
    return 0;
}