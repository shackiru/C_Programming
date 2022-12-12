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
    printf("\n");

    // case 2-> insert last atau after tail
    struct node *temp1 = createNode(10);
    tail -> next = temp1;
    temp1 -> prev = tail;
    tail = temp1;

    printf("\n");

    iter = head;
    while(iter)
    {
        printf("%d\n", iter -> val);
        iter = iter -> next;
    }
    printf("\n");
    struct node *iterBack = tail;
    while(iterBack)
    {
        printf("%d\n", iterBack -> val);
        iterBack = iterBack -> prev;    
    }

    //case 3 insert head
    struct node *temp2 = createNode(7);
    temp2 -> next = head;
    head -> prev = temp2;
    head = temp2;

    printf("\n");

    iter = head;
    while(iter)
    {
        printf("%d\n", iter -> val);
        iter = iter -> next;
    }
    printf("\n");

    //case 4 insert between head and tail
    struct node *a = head;
    struct node *b = tail;
    struct node *temp3 = createNode(3);

    printf("\n");

    temp3 -> next = b;
    temp3 -> prev = a;

    iter = head;
    while(iter)
    {
        printf("%d\n", iter -> val);
        iter = iter -> next;
    }
    printf("\n");

    // delete head
    head = head -> next;
    free(head -> prev);
    head -> prev = NULL;

    printf("\n");

    iter = head;
    while(iter)
    {
        printf("%d\n", iter -> val);
        iter = iter -> next;
    }

    //delete tail
    tail = tail ->prev;
    free(tail -> next);
    tail -> next = NULL;

    iter = head;
    while(iter)
    {
        printf("%d\n", iter -> val);
        iter = iter -> next;
    }
    printf("\n");

    // delete by index
    struct node *iter = head;
    int x = 10;
    // find element that want to be deleted
    while(iter -> next -> val != x)
    {
        iter = iter -> next;
    }
    struct node *a = iter;
    struct node *del = iter -> next;
    struct node *b = iter -> next ->next;
    a -> next = b;
    a -> prev = a;
    
    return 0;
}