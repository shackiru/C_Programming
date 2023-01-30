#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int SIZE = 26;

struct Node
{
    char name[105];
    int age;
}*table[SIZE];

Node *createNode(const char *name, const int age)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    return newNode;
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
        table[key] = createNode(name, age);
        return;
    }

    int curr = key + 1;
    while(curr != key && table[curr] != NULL)
    {
        curr = (curr + 1) % SIZE;
    }

    if(curr == key)
    {
        printf("Table is full\n");
    }
    table[curr] = createNode(name, age);
}

void view()
{
    for(int i = 0; i < SIZE ; i++)
    {
        printf("%d." , i);
        if(table[i])
        {
            printf("%s - %d\n", table[i]->name, table[i]->age);
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
    if(table[key] && strcmp(table[key]->name, name) == 0)
    {
        free(table[key]);
        table[key] = NULL;
        return;
    }

    int curr = key + 1;
    while(curr != key && (table[curr] == NULL || strcmp(table[curr]->name, name) != 0))
    {
        curr = (curr + 1) % SIZE;
    }

    if(curr == key)
    {
        printf("%s not found\n", name);
    }

    free(table[curr]);
    table[curr] = NULL;
}

int main()
{
    insert("Alvin", 10);
    insert("Anton", 18);
    insert("Budi", 19);

    deleteNode("Fredy");
    deleteNode("Anton");

    view();

    return 0;
}
