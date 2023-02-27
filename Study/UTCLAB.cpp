#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define SIZE 100

int flag = 0;

struct tnode
{
    char name[55];
    char phone[55];
    char type[55];
    int night;
    char id[55];
    tnode *next;
};

tnode * head[SIZE];


void init()
{
    for(int i = 0; i < SIZE; i++)
    {
        head[i] = NULL;
    }
}

int hashFunc(char id[])
{
    int a = id[2] - '0' + id[3] - '0' + id[4] - '0';
    a = a - 1;
    return a % SIZE;
}

tnode *createNode(char *name, char *phone, char *type, int night, char *id)
{
    tnode *temp = (tnode *) malloc(sizeof(tnode));
    strcpy(temp->name, name);
    strcpy(temp->phone, phone);
    strcpy(temp->type, type);
    strcpy(temp->id, id);
    temp->night = night;
    
    return temp;
}

void insertNode(char * name, char * phone, char * type, int night, char * id)
{
    int key = hashFunc(id);
    tnode * temp = createNode(name, phone, type, night, id);

    if(head[key] == NULL)
    {
        head[key] = temp;
    }
    else
    {
        tnode *curr = head[key];
        while(curr->next)
        {
            curr = curr->next;
        }
        curr->next = temp;
    }
}

void insert()
{
    srand(time(0));
    flag = 1;
    char name[55]; char phone[55]; char phoneCheck[55];
    char *split; char id[55]; char type[55];
    int count = 0; int age; int night;
    bool check = false;
    do
    {
        printf("input full name[3 - 30]: ");
        scanf("%[^\n]", name); getchar();
        if(strlen(name) < 3 || strlen(name) > 30)
        {
            printf("invalid input format!\n");
        }
    } while (strlen(name) < 3 || strlen(name) > 30);
    
    do
    {
        check = false;
        count = 0;
        printf("input phone number: ");
        scanf("%[^\n]", phone); getchar();
        strcpy(phoneCheck, phone);
        split = strtok(phoneCheck, " ");
        if(strcmp(split, "+62") != 0)
        {
            printf("Phone number must begin with +62\n");
        }

        for(int i = 3; i < strlen(phone); i++)
        {
            if(isdigit(phone[i]))
            {
                count++;
            }
            else if(phone[i] == ' ')
            {
            
            }
            else
            {
                check = true;
            }
        }
    } while (strcmp(split, "+62") != 0 || count != 11 || check);   

    do
    {
        printf("enter your age [minimum 18]: ");
        scanf("%d", &age); getchar();
        if(age < 18)
        {
            printf("age must be minumum 18 y.o\n");
        }
    } while (age < 18);

    do
    {
        printf("how many night you will stay [1-30]: ");
        scanf("%d", &night); getchar();
        if(night < 1 || night > 30)
        {
            printf("you can't stay than 1 night or more than 30 nights\n");   
        }
    } while (night < 1 || night > 30);
    sprintf(id, "%c%c%d%d%d", toupper(type[0]), toupper(type[1]), rand() % 10, rand % 10, rand % 10);
    
}

int main()
{

    return 0;
}