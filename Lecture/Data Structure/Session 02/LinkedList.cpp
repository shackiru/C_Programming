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

    struct tNode *node = (struct tNode*) malloc (sizeof(struct tNode));
    node -> val = 25;
    node -> next = head;
    head = node;

    struct tNode *p = head;

    while(p != NULL)
    {
        printf("%d\n", p -> val);
        p = p -> next;
    }

    return 0;
}