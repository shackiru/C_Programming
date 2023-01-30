#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int SIZE = 26;

struct Node
{
    char name[105];
    int age;
    Node *next, *prev;
};

struct Row
{
    Node *head, *tail;
}*table[SIZE];


Node *createNode(const char *name, const int age)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    return newNode;
}

Row *createRow()
{
    Row *newRow = (Row *)malloc(sizeof(Row));
    newRow->head = newRow->tail = NULL;
    return newRow;
}

int hashing(const char *name)
{
    char c = name[0];
    if(c >= 'A' && c <= 'Z')
    {
        return c - 'A';
    }
    else if(c >= 'a' && c <= 'z')
    {
        return c - 'a';
    }
    return c % SIZE;
}

void insert(const char *name, const int age)
{
    int key = hashing(name);
    if(table[key] == NULL)
    {
        table[key] = createRow();
        table[key]->head = table[key]->tail = createNode(name, age);
        return;
    }
    Row *r = table[key];

    if(strcmp(r->head->name, name) > 0)
    {
        Node *newNode = createNode(name, age);
        newNode->next = r->head;
        r->head->prev = newNode;
        r->head = newNode;
        return;
    }
    else if(strcmp(r->tail->name, name) < 0)
    {
        Node *newNode = createNode(name, age);
        newNode->prev = r->tail;
        r->tail->next = newNode;
        r->tail = newNode;
        return;
    }
    else
    {
        Node *curr = r->head;
        while(curr)
        {
            if(strcmp(curr->name, name) > 0)
            {
                Node *newNode = createNode(name, age);
                newNode->next = curr;
                newNode->prev = curr->prev;
                curr->prev->next = newNode;
                curr->prev = newNode;
                return;
            }
            curr = curr->next;
        }
    }
}

void view()
{
    for(int i = 0; i < SIZE ; i++)
    {
        printf("%d." , i);
        Row *row = table[i];
        if(row)
        {
            Node *curr = row->head;
            while(curr)
            {
                printf("%s - %d --> ", curr->name, curr->age);
                curr = curr->next;
            }
            printf("\n");
        }
        else
        {
            printf("-\n");
        }
    }
}

void deleteNode(const char *name)
{
    int key = hashing(name);

}

int main()
{
    insert("Alvin", 10);
    insert("Anton", 18);
    insert("Budi", 19);

    deleteNode("Alvin");
    deleteNode("Anton");
    deleteNode("Budi");

    view();

    return 0;
}
