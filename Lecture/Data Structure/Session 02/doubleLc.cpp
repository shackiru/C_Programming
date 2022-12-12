#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *prev;
    struct node *next;
};

struct node *head = 0;
struct node *tail = 0;

struct node *createNode(int x)
{
    struct node *temp = (struct node*) malloc (sizeof(struct node));
    temp -> val = x;
    temp -> prev = NULL;
    temp -> next = NULL;
    return temp;
}

int main()
{
    if(head == NULL && tail == NULL)
    {
        head = tail = createNode(5);
    }
    struct node *iter = head;
    while(iter)
    {
        printf("%d\n", iter -> val);
        iter = iter -> next;
    }

    // case 2-> insert last atau after tail
    struct node *temp = createNode(10);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;

    return 0;
}