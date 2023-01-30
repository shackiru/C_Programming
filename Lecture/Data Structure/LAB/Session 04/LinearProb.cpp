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

int main()
{

    return 0;
}