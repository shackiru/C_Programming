#include <stdio.h>
#include <stdlib.h>

struct tNode
{
    int val;
    struct tNode *next;
};

struct tNode *head;

int main()
{
    struct tNode *head = (struct tNode*) malloc (sizeof (struct tNode));
    head -> val = 10;
    head -> next = NULL;
    
    struct tNode *iter = head;
    //traversal
    while(iter != NULL)
    {
        printf("%d\n", iter -> val);
        iter = iter -> next;
    }

    struct tNode *nw = (struct tNode*)malloc(sizeof(struct tNode));

    nw -> val = 25;
    nw -> next = NULL;
    
    nw -> next = head;
    head = nw;

    while(iter)
    {
        printf("%d\n", iter -> val);
        iter = iter -> next;
    }

    struct tNode *newBack = (struct tNode*) malloc (sizeof(struct tNode));
    newBack -> val = 8;
    newBack -> next = NULL;

    struct tNode *curr = head;
    while(curr -> next != NULL)
    {
        curr = curr -> next;
    }

    curr -> next = newBack;
    iter = head;
    while(iter)
    {
        printf("%d\n", iter -> val);
        iter = iter -> next;
    }

    //delete element
    struct tNode *iterDel = head;
    int x = 25;
    //if elemet to be deleted is the head
    if(head -> val == x)
    {
        head = head -> next;
        free(iterDel);
    }
    else
    {
        while(iterDel -> next -> val)
        {
            iterDel = iterDel -> next;
            struct tNode *del = iterDel -> next;
            iterDel -> next = del -> next;
        }
    }

    iter = head;

    while(iter)
    {
        printf("%d\n", iter -> val);
        iter = iter -> next;
    }
    
    return 0;
}