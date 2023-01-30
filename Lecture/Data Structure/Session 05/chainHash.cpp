#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 5

struct node
{
    char s[50];
    struct node *next;
}*hashTable[MAXSIZE];

int hashing(char s[])
{
    return s[0] - 'a';
}

struct node * initNode()
{

}

void initTable()
{
    for(int i = 0; i < MAXSIZE; i++)
    {
        hashTable[i] = NULL;
    }
}

void insert(char s[])
{
    int key = hashing(s) % MAXSIZE;
    if(hashTable[key] == NULL)
    {
        hashTable[key] = (struct node *) malloc (sizeof(struct node));
        strcpy(hashTable[key]->s, s);
        hashTable[key]->next = NULL;
    }
    else
    {
        struct node *temp = (struct node *) malloc (sizeof(struct node));
        strcpy(temp->s, s);
        temp->next = NULL;

        struct node *iter = hashTable[key];
        while(iter->next != NULL)
        {
            iter = iter->next;
        }
        iter->next = temp;
    }
}

void print()
{
    for(int i = 0; i < MAXSIZE; i++)
    {
        printf("%d -> ", i);
        struct node * iter = hashTable[i];
        while(iter)
        {
            printf("%s", iter->s);
            iter = iter->next;
        }
        printf("\n");
    }
}

int main()
{
    char s[50];
    for(int i = 0; i < MAXSIZE; i++)
    {
        scanf("%s" , s);
        getchar();
        insert(s);
        print();
    }

    return 0;
}